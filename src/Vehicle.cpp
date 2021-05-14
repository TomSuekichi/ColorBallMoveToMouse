//
//  Vehicle.cpp
//  VirtualCreature
//
//  Created by 末吉知樹 on 2021/04/28.
//

#include "Vehicle.hpp"

void Vehicle::setup(){
    location=ofVec2f(ofRandom(100,1180),ofRandom(100,620));
    velocity=ofVec2f(0,0);
    acceleration=ofVec2f(0,0);
    maxSpeed=ofRandom(5,15);
    color=ofRandom(0,360);
}

void Vehicle::draw(){
    ofSetHSVColor(color, 100, 100, 100);
    ofDrawCircle(location, 10);
}
void Vehicle::seek(ofVec2f target){
    ofVec2f desired=target-location;
    float d=desired.length();
    desired.normalize();
    if(d<100){
        float m=d*maxSpeed/100;
        desired*=m;
    }else{
        desired*=maxSpeed;
    }
    acceleration*=0;
    ofVec2f steer=desired-velocity;
    if(steer.length()>maxForce){
        steer*=(maxForce/steer.length());
    }
    applyForce(steer);
    velocity+=acceleration;
    location+=velocity;
}

void Vehicle::applyForce(ofVec2f force){
    acceleration+=force;
}

void Vehicle::ofSetHSVColor(int _h, int _s, int _v, int _a) {
    float s = (float)_s / 100, v = (float)_v / 100;
    if (s == 0) {
        ofSetColor(255 * v, 255 * v, 255 * v);
        return;
    }
    float r, g, b;
    int hi = (int)(floor((double)_h / 60)) % 6;
    float f = (float)_h / 60 - (float)hi;
    float p = v * (1 - s);
    float q = v * (1 - f * s);
    float t = v * (1 - (1 - f)*s);
    switch (hi) {
        case 0:
            r = v;
            g = t;
            b = p;
            break;
        case 1:
            r = q;
            g = v;
            b = p;
            break;
        case 2:
            r = p;
            g = v;
            b = t;
            break;
        case 3:
            r = p;
            g = q;
            b = v;
            break;
        case 4:
            r = t;
            g = p;
            b = v;
            break;
        case 5:
            r = v;
            g = p;
            b = q;
            break;
        default:
            break;
    }
    ofSetColor(255 * r, 255 * g, 255 * b, _a);
}

void Vehicle::ofSetHSVColor(int _h, int _s, int _v) {
    ofSetHSVColor(_h, _s, _v, 255);
}
