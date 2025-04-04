#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(29.97);
    ofSetVerticalSync(true);
    ofSetWindowTitle("Synchronator");

    redFbo.allocate(ofGetWidth(), ofGetHeight());
    greenFbo.allocate(ofGetWidth(), ofGetHeight());
    blueFbo.allocate(ofGetWidth(), ofGetHeight());
    mixerFbo.allocate(ofGetWidth(), ofGetHeight());

    redShader.load("shadersGL3/default.vert", "shadersGL3/red.frag");
    greenShader.load("shadersGL3/default.vert", "shadersGL3/green.frag");
    blueShader.load("shadersGL3/default.vert", "shadersGL3/blue.frag");
    mixerShader.load("shadersGL3/default.vert", "shadersGL3/mixer.frag");
}

//--------------------------------------------------------------
void ofApp::update(){
    redFbo.begin();
    ofClear(0, 0, 0, 255);
    redShader.begin();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    redShader.end();
    redFbo.end();

    greenFbo.begin();
    ofClear(0, 0, 0, 255);
    greenShader.begin();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    greenShader.end();
    greenFbo.end();

    blueFbo.begin();
    ofClear(0, 0, 0, 255);
    blueShader.begin();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    blueShader.end();
    blueFbo.end();

    mixerFbo.begin();
    ofClear(0, 0, 0, 255);
    mixerShader.begin();
    mixerShader.setUniformTexture("red", redFbo.getTexture(), 0);
    mixerShader.setUniformTexture("green", greenFbo.getTexture(), 1);
    mixerShader.setUniformTexture("blue", blueFbo.getTexture(), 2);
    mixerShader.setUniform1f("colorOn", colorOn);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    mixerShader.end();
    mixerFbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
    mixerFbo.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'g') {
        colorOn = (colorOn == 0.0f) ? 1.0f : 0.0f;
        ofLog() << "colorOn: " << colorOn;
    }
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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
