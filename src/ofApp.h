#pragma once

#include "ofMain.h"
#include "ofxGifDecoder.h"
#include "ofxGifEncoder.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();

		void keyPressed(int key);
		void mouseMoved(int x, int y );
		
        ofVideoGrabber vid;
        vector<ofImage> session;
    
        void onGifSaved(string & fileName);
        ofxGifDecoder decoder;
        ofxGifEncoder encoder;
        ofxGifFile file;
    
        int counter;
        bool drawGif;
        uint64_t actualTime;
};
