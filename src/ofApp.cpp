
#include "ofApp.h"
float theta_min = -25;
float theta_max = 60;

float scale_min = 0.6;
float scale_max = 0.92;

float initLength = 120;

int framenum;
int speed;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(10);
    ofSetColor(255);
    ofSetLineWidth(1);
    
    light.enable();
    light.setAmbientColor(200);
    
    ofEnableDepthTest();
    
    speed = 1;
    once = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    framenum += speed;
    scale_min = ofRandom(0.6, 0.7);
    initLength = ofRandom(80, 150);
    
}
//--------------------------------------------------------------
void ofApp::draw(){
   

    if(framenum >= 10 || framenum <= 0){
        speed *= -1;
    }
    
   ofBackground(ofColor::fromHsb(150 + framenum, 230 - framenum, 245 - framenum));
       ofSetColor(0);
    if(once){
        drawTree();
        once = false;
    }
}

void ofApp::drawTree(){
    ofTranslate(mouseX,mouseY,0);

//    ofTranslate(ofGetWidth()/2,ofGetHeight(),0);
//    float translate_x = ofRandom(-ofGetWidth()/3, ofGetWidth()/3);
//    float translate_y = ofRandom(-ofGetHeight()/3, ofGetHeight()/3);
//    float translate_z = ofRandom(-initLength/5, initLength/5);
//    ofTranslate(translate_x, translate_y, translate_z);
    ofDrawLine(0, 0, 0,-27 + initLength * scale_min/3, -initLength, initLength/6);
    ofTranslate(-27 + initLength * scale_min/3, -initLength,initLength/6);
    branch(initLength);
}

void ofApp::branch(float h){
    float scale_min = 0.65 + 0.05*(ofGetMouseX()/ofGetWidth());
    
    h *= ofRandom(scale_min, scale_max);
    
    if(h>5){
        ofPushMatrix();
        float theta_z = ofRandom(theta_min, theta_max);
        ofRotateZ(theta_z);
        float theta_y = ofRandom(theta_min, theta_max);
        ofRotateY(theta_y);
        float theta_x = ofRandom(theta_min, theta_max);
        ofRotateX(theta_x);
        ofDrawLine(0, 0, 0, 0, -h, 0);
        ofTranslate(0, -h, 0);
        branch(h);
        branch(h);
        ofPopMatrix();
    }
}


void ofApp::lineWidth(float h){
    if(h>5){
        ofSetLineWidth(h * ofRandom(0.05, 0.1));
    }else{
        ofSetLineWidth(0.5);
    }
    
    
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    once = true;
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
