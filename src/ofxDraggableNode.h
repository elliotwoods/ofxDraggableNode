//
//  ofxDraggableNode.h
//  ofxDraggableNode
//
//  Created by Elliot Woods on 10/11/2011.
//	http://www.kimchiandchips.com
//
#include "of3dMouseEventArgs.h"
#include "ofNode.h"

class ofxDraggableNode : public of3dMouseEventArgsListener {
public:
	ofxDraggableNode(float radius = 1.0f);
	void init(ofNode& node);

	////
	//of3dMouseEventArgsListener
	//
	bool isInside(const ofVec3f& position) const;
	void mouseDragged(const of3dMouseEventArgs& action);
	//
	////

protected:
	ofNode* node;
	float radius;
};