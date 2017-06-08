//
//  Image.hpp
//  ImgFlow
//
//  Created by Hidemaro Fujinami on 2017/06/05.
//
//

#ifndef Image_hpp
#define Image_hpp

#include "ofMain.h"


class Image {
    
public:
    
    ofImage img;
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f noise;
    ofVec2f initial_pos;
    float noise_level;
    bool move = false;
    float img_size;
    
    void load(string path);
    void setPosition(ofVec2f _pos);
    void setVelocity(ofVec2f _vel);
    void addNoise(ofVec2f _noise);
    void setNoiseLevel(float _noiselevel);
    void update();
    void draw();
    void stop();
    
private:
    
};

#endif
