#include "../../include/Objects/AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
	: animFPS(24)
	, frameTime(0)
{
}

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::draw()
{
	image.setPosition(this->getPosition());
	image.setScale(this->getScale());
	image.setRotation(this->getRotation());
	image.draw();
}

void AnimatedSprite::update(float deltaTime)
{
	// Update how long the current frame has been displayed
	frameTime += deltaTime / 1000; // Convert to sec
	// This check determines if it's time to change to the next frame.
	if (frameTime > (1 / animFPS))
		// The number of frames to increment is 
		// frameTime / (1 / animFPS) == frameTime * animFPS
		frameNum += frameTime * animFPS;
			
	// Check if we've advanced past the last frame, and must wrap.
	if (frameNum >= animData.frameInfo[animNum].numFrames)
		frameNum = frameNum % animData.frameInfo[animNum].numFrames;
	// Update the active image.
	// (startFrame is relative to all the images, while frameNum is
	// relative to the first frame of this particular animation).
	int imageNum = (animData.frameInfo[animNum].startFrame + frameNum) 
		% animData.frameInfo[animNum].numFrames;
	image = *(animData.images[imageNum]);
	// We use fmod (floating point modulus) for the same reason
	// as the % above.
	frameTime = fmod(frameTime, 1 / animFPS);

	Updatable::update(deltaTime);
}

void AnimatedSprite::initalize(AnimData data, int startingAnimNum)
{
	animData = data;
	changeAnim(startingAnimNum);
}

void AnimatedSprite::changeAnim(int newAnimNum)
{
	animNum = newAnimNum;
	// The active animation is now at frame 0 and 0.0f time
	frameNum = 0;
	//animTime = 0.0f;
	// Set active image, which is just the starting frame.
	int imageNum = animData.frameInfo[animNum].startFrame;
	auto tmp = animData.images[imageNum];
	image = *tmp;
}

void AnimatedSprite::removeChild(Node * child)
{
	Node::removeChild(child);
	Updatable::removeChild(child);
}

void AnimatedSprite::insertChild(Node * child)
{
	Node::insertChild(child, 0, "");
	Updatable::insertChild(child);
}
