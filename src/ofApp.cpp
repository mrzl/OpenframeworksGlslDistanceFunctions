#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableArbTex();
    ofSetFullscreen(true);
    ofSetFrameRate(1000);
    ofSetVerticalSync(false);
    //shader.load("shader/sphere_raytrace");
    //shader.load("shader/path_trace01");
    shader.load("shader/iq_dist");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
      ofSetWindowTitle(ofToString(ofGetFrameRate()));

      shader.begin();
      shader.setUniform3f("iResolution", ofGetWidth(), ofGetHeight(), 0.0);
      shader.setUniform1f("iGlobalTime", ofGetElapsedTimef());
      shader.setUniform4f("iMouse", (float)(draggedX), (float)(draggedY), (float)(clickX), (float)(clickY));
      shader.setUniform3f("boxPos", boxposX, 0, boxposY);
      ofRect(0, 0, ofGetWidth(), ofGetHeight());

      shader.end();

      ofSetColor(0);
      ofDrawBitmapString(ofToString(ofGetFrameRate()), 100, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
  boxposX = ofMap(x, 0, ofGetWidth(), -1, 1);
  boxposY = ofMap(y, 0, ofGetHeight(), -1, 1);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
  draggedX = x;
  draggedY = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  clickX = x;
  clickY = y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
