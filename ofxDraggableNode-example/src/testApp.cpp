#include "testApp.h"

testNode::testNode() {
	ofCamera::setNearClip(0.1f);
}

void testNode::customDraw() {
	ofPushStyle();
	ofNoFill();
	ofBox(1.0f);
	ofFill();
	ofSetColor(100, 100, 200);
	ofSphere(0.3f);
	ofSetLineWidth(3.0f);
	ofSetColor(255);
	ofLine(ofVec3f(0,0,0), ofVec3f(0,0,-1));
	ofPopStyle();
}

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(100);

	interactiveNode.init(node);
	camera.addInteractiveElement(interactiveNode);
	node.setPosition(5.0f, 5.0f, 5.0f);

	viewports[0] = ofRectangle(0,0,ofGetWidth()/2, ofGetHeight());
	viewports[1] = viewports[0];
	viewports[1].x += viewports[0].width;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	camera.begin(viewports[0]);
	drawScene();
	node.draw();
	camera.end();

	node.begin(viewports[1]);
	drawScene();
	node.end();

	ofPushStyle();
	ofSetLineWidth(2.0f);
	ofNoFill();
	ofRect(viewports[0]);
	ofRect(viewports[1]);
	ofPopStyle();
}

//--------------------------------------------------------------
void testApp::drawScene(){
	ofPushStyle();
	ofSetColor(200, 100, 100);
	ofDrawGrid(10.0f, 5.0f, true);
	ofPopStyle();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key=='c')
		camera.toggleCursorDraw();	
}