//
//  Image.cpp
//  ImgFlow
//
//  Created by Hidemaro Fujinami on 2017/06/05.
//
//

#include "Image.hpp"

void Image::load(string path){
    
    img.load(path);

    img_size = img.getHeight() * img.getWidth();
    
    
}

void Image::setPosition(ofVec2f _pos){
    initial_pos = _pos;
    pos = _pos;
}

void Image::setVelocity(ofVec2f _vel){
    vel = _vel * (ofNoise(noise) * noise_level);
}

void Image::addNoise(ofVec2f _noise){
    noise = _noise;
}

void Image::setNoiseLevel(float _noiselevel){
    noise_level = _noiselevel;
}

void Image::update(){
    ofVec2f vector  = initial_pos - pos;
    
    if(vel.x != 0) {
        pos.x += vel.x;
        move = true;
    }
    
    if(vel.y != 0) {
        pos.y += vel.y;
        move = true;
    }
    
    if(vel.x == 0 && vel.y == 0){
        move = false;
    }
    
    if(!move) {
        vel = ofVec2f(0,0);
        
        if (abs(vector.x) < 0.1){
            pos.x = initial_pos.x;
        } else {
            pos.x += vector.x /10;
        }
        
        
        if (abs(vector.y) < 0.1){
            pos.y = initial_pos.y;
        } else {
            pos.y += vector.y /10;
        }

    }

}

void Image::draw() {
    if (pos.x < -ofGetWidth()/2) {
        pos.x = pos.x + ofGetWidth()*2.0;
    } else if (pos.x > ofGetWidth() * 1.5) {
        pos.x = pos.x - ofGetWidth()*2.0;
    }
    
    if (pos.y < -ofGetHeight()/2) {
        pos.y = pos.y + ofGetHeight()*2.0;
    } else if (pos.y > ofGetHeight() * 1.5) {
        pos.y = pos.y - ofGetHeight()*2.0;
    }
    
    img.draw(pos.x, pos.y);
}

void Image::stop() {
    move = false;
}
