#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(255);
	ofEnableDepthTest();
	ofSetWindowTitle("Insta");
		
	this->icoSphere.setRadius(300);	
	this->icoSphere.setResolution(5);

	this->triangles = icoSphere.getMesh().getUniqueFaces();

	this->light.setAreaLight(2048, 2048);
	this->light.setAmbientColor(ofFloatColor(0.0, 0.0, 0.0, 1.0));
	this->light.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	this->light.setSpecularColor(ofFloatColor(1.0, 0.0, 0.0));

	noise_x = ofRandom(10);
	noise_y = ofRandom(10);
	noise_z = ofRandom(10);

	ofSetColor(30);	
}

//--------------------------------------------------------------
void ofApp::update(){
	this->light.setPosition(this->cam.getPosition().normalize() * 2048);
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofEnableLighting();
	this->light.enable();

	cam.begin();

	ofRotateY(ofGetFrameNum() % 360);
		
	float noise_value;
	ofColor color;
	float box_size = 3;

	for (int i = 0; i < this->triangles.size(); i++) {
		ofVec3f avg = (this->triangles[i].getVertex(0) + this->triangles[i].getVertex(1) + this->triangles[i].getVertex(2)) / 3;
		noise_value = ofNoise(avg.x * 0.0025, avg.y * 0.0025, avg.z * 0.0025, ofGetFrameNum() * 0.05);
		avg = avg.normalized() * 300 * noise_value;

		ofBox(avg, box_size * noise_value);
	}

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
