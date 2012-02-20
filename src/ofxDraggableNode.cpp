//
//  ofxDraggableNode.cpp
//  ofxDraggableNode
//
//  Created by Elliot Woods on 10/11/2011.
//	http://www.kimchiandchips.com
//
#include "ofxDraggableNode.h"

ofxDraggableNode::ofxDraggableNode(float radius) {
	this->node = 0;
	this->radius = radius;
}

void ofxDraggableNode::init(ofNode& node) {
	this->node = &node;
}

bool ofxDraggableNode::isInside(const ofVec3f& position) const {
	if (this->node != 0)
		return (position - this->node->getGlobalPosition()).length() <= radius;
}

void ofxDraggableNode::mouseDragged(const of3dMouseEventArgs& action) {
	if (this->node != 0) {
		if (action.getButton()==0)
			this->node->move(action.getWorldMovement());
		else if (action.getButton()==2) {
			ofQuaternion q;
			ofVec3f lastMouse = action.getWorld() - action.getWorldMovement();
			q.makeRotate(lastMouse - node->getGlobalPosition(), action.getWorld() - node->getGlobalPosition());
			this->node->rotate(q);
		}
	}
}