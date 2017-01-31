#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    vid.initGrabber(320,240);
    encoder.setup(320, 240);
    ofAddListener(ofxGifEncoder::OFX_GIF_SAVE_FINISHED, this, &ofApp::onGifSaved);
    counter = 0;
    drawGif = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    vid.update();
    actualTime = ofGetElapsedTimeMillis();
    if (session.size() != 0) {
        counter = (actualTime / 125) % session.size();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (session.size() != 0) {
        ofBackground(0);
        vid.draw(0, 0);
        if (drawGif) {
            session[counter].draw(320, 0);
        }
        if (!drawGif) {
            for( int i = 0; i < session.size(); i++ ){
                session[i].draw(  (i%4 * 320) , ((int)(i/4)*240) + 240 );
            }
        }
    }
    else{
        ofBackground(0);
        vid.draw(0, 0);
        ofSetColor(ofColor::papayaWhip);
        ofDrawBitmapStringHighlight("session == NULL", 330, 10);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ofImage temporal;
    switch (key) {
        case ' ':
            temporal.allocate( vid.getPixels().getWidth() , vid.getPixels().getHeight() , vid.getPixels().getImageType() );
            temporal.setFromPixels( vid.getPixels() );
            session.push_back( temporal );
            
            break;
        case 's':
            for (int i = 0; i < session.size(); i++) {
                encoder.addFrame(session[i]);
            }
            cout<<"start saving"<<endl;
            encoder.save("test5.gif");
            cout<<"finish saving"<<endl;
            drawGif = true;
            break;
        case 'v':
            
            break;
        default:
            
            break;
    }
}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::exit(){
    encoder.exit();
}

//--------------------------------------------------------------

void ofApp::onGifSaved(string &fileName) {
    cout << "gif saved as " << fileName << endl;
}
