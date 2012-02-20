#pragma once

#include "ofMain.h"
#include "ofxGrabCam.h"
#include "ofxDraggableNode.h"

class testNode : public ofCamera {
public:
	testNode();
protected:
	void customDraw();
	ofLight light;
};


class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
	void drawScene();
	void keyPressed  (int key);

	ofxGrabCam camera;
	testNode node;
	ofxDraggableNode interactiveNode;

	ofRectangle viewports[2];
};
