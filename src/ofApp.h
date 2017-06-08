#pragma once 

#define NUM 40

#include "ofMain.h"
#include "Image.hpp"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
    Image img_array[NUM];

    ofxPanel gui;
    ofxVec2Slider velocity;
    ofxFloatSlider noise_level;
    
    ofVec2f vel_noise = ofVec2f(0.0, 0.0);
    
    ofShader shader;
};
