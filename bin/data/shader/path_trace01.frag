uniform vec3 iResolution;
uniform float iGlobalTime;

void main(void) {
  vec2 uv = (-1.0 + 2.0*gl_FragCoord.xy / iResolution.xy) * vec2(iResolution.x/iResolution.y, 1.0);
  vec3 ro = vec3(0.0, 0.0, -6.0);     // Ray origin.
  vec3 rd = normalize(vec3(uv, 1.0)); // Ray direction.
  vec3 transmit = vec3(1.0);          // How much light the ray lets through.
  vec3 light = vec3(0.0);             // How much light hits the eye through the ray.

  float epsilon = 0.001;

  float bounce_count = 2.0; // How many rays we trace.

  for (int i=0; i<bounce_count; i++) {
    float dist = intersect(ro, rd);
    if (dist > 0.0) { // Object hit.
      transmit *= material(ro, rd); // Make the ray more opaque.
      vec3 nml = normal(ro, rd);    // Get surface normal for reflecting the ray.
      ro += rd*dist;                // Move the ray to the hit point.
      rd = reflect(rd, nml);        // Reflect the ray.
      ro += rd*epsilon;             // Move the ray off the surface to avoid hitting the same point twice.
    } else { // Background hit.
      light += transmit * background(rd); // Put the background light through the ray and add it to the light seen by the eye.
      break;                              // Don't bounce off the background.
    }
  }

  gl_FragColor = vec4(light, 1.0); // Set pixel color to the amount of light seen.
}
