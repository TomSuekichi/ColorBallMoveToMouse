#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
//    vehicle.setup();
//    ofSetBackgroundAuto(false);
    for(int i=0; i<500; i++){
        Vehicle vehicle;
        vehicle.setup();
        vehicles.push_back(vehicle);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<500; i++){
        vehicles[i].seek(ofVec2f(ofGetMouseX(),ofGetMouseY()));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for(int i=0; i<500; i++){
    vehicles[i].draw();
    }
    ofSetColor(0,25);
//    ofDrawCircle(ofGetMouseX(),ofGetMouseY(), 5);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
