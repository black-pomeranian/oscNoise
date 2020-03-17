// Refer to the README.md in the example's root folder for more information on usage

#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    counter = 0;
    ofSetCircleResolution(50);
    ofBackground(255,255,255);
    
    receiver.setup(PORT);
    
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    while (receiver.hasWaitingMessages()) {
        
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        if(m.getAddress() == "/oscControl/slider1"){
            color = m.getArgAsFloat(0)*255;
        }
        
        if(m.getAddress() == "/oscControl/slider2"){
            change = m.getArgAsFloat(0)*200;
        }
        
        if(m.getAddress() == "/oscControl/slider3"){
            num = m.getArgAsFloat(0)*200;
        }
        
        if(m.getAddress() == "/oscControl/slider4"){
            change = m.getArgAsFloat(0);
        }
    }
    counter = counter + 0.033f;
}

//--------------------------------------------------------------
void ofApp::draw(){

    //--------------------------- rectangles
    ofFill();
    for (int i = 0; i < 200; i++){
        
        for (int j = 0; j < change; j++) {
            ofSetColor((int)ofRandom(0,color),(int)ofRandom(0,color),(int)ofRandom(0,color));
            ofDrawRectangle(ofRandom(-250,ofGetWidth()),ofRandom(-250,ofGetHeight()),ofRandom(10,250),ofRandom(10,250));
        }
        
        for (int j = 0; j < num - change; j++) {
            ofSetColor((int)ofRandom(0,color),(int)ofRandom(0,color),(int)ofRandom(0,color));
            location += ofNoise(-1, 10);
            ofDrawLine(location, 0, location, ofGetHeight());
            
            if (location >= ofGetWidth()) {
                location = 0;
            }
        }
    }
    ofSetHexColor(0x000000);
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){

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
