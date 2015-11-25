#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    
    urg.setMode(ofx::Urg::DISTANCE);
    urg.setupSerial();
    
    ofLogNotice("Product", urg.productType());
    ofLogNotice("Serial", urg.serialId());
    ofLogNotice("Status", urg.status());
    ofLogNotice("State", urg.state());
    ofLogNotice("Firmware version", urg.firmwareVersion());
    
    gui.setup();
    gui.add(sliderScale.setup("Scale", 2.4, 0.01, 3));
    gui.add(sliderX.setup("X", 100, -1000, 1000));
    gui.add(sliderY.setup("Y", 100, -1000, 1000));
    
    urg.start();
}

//--------------------------------------------------------------
void ofApp::update(){
    urg.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
//    cam.begin();
    ofPushMatrix();
    float s = sliderScale;
    ofTranslate(sliderX, sliderY);
    ofRotateX(180);
    ofRotateZ(-90);
    ofScale(s, s, s);
    urg.drawData();
//  urg.drawDebugPolar();
    ofPopMatrix();
//    cam.end();
    
//  urg.drawData();
    
    ofDrawBitmapString(ofToString(ofGetFrameRate(), 0), 20, 80);
    if (!urg.isFrameCaptured()) {
        ofDrawBitmapString("frame is not captured", 20, 100);
    } else {
        ofDrawBitmapString("frame is captured", 20, 120);
    }
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        urg.captureData();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
