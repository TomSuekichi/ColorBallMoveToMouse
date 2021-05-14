#pragma once
#include "ofMain.h"

class Vehicle{
public:
    void setup();
    void seek(ofVec2f target);
    void applyForce(ofVec2f force);
    void draw();
    void ofSetHSVColor(int _h, int _s, int _v);
    void ofSetHSVColor(int _h, int _s, int _v, int _a);
    
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float maxSpeed;
    float maxForce=0.1;
    float color;
};
