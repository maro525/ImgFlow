#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    shader.load("shader/shader.vert", "shader/shader.frag");
    
    for (int i = 0; i < NUM; i++){
        img_array[i].load("jpg" + ofToString(i) + ".png");
        ofVec2f pos;
        pos.set(10 + 200*(i%5), 10 + 100*(i/5));
        img_array[i].setPosition(pos);
        vel_noise += ofVec2f(0.1, 0.1);
        img_array[i].addNoise(vel_noise);
    }
    
    gui.setup();
    ofVec2f initVel = ofVec2f(0,0);
    ofVec2f minVel = ofVec2f(-10, -10);
    ofVec2f maxVel = ofVec2f(10,10);
    gui.add(velocity.setup("velocity", initVel, minVel, maxVel));
    gui.add(noise_level.setup("noise_level", 0.5, 0.0, 0.9));
    
}

//--------t------------------------------------------------------
void ofApp::update(){
   
    for (int i = 0; i < NUM; i++){
        img_array[i].setVelocity(velocity);
        img_array[i].setNoiseLevel(noise_level);
        img_array[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    shader.begin();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
    
    for (int i = 0; i < NUM; i++){
        img_array[i].draw();
    }

    gui.draw();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' ') {
        velocity = ofVec2f(0,0);
        for (int i = 0; i < NUM; i++) {
            img_array[i].stop();
        }
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
