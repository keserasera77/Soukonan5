#include "GameLib/Framework.h"
#include "Sequence/Child.h"
#include "Sequence/Parent.h"
#include "Sequence/Select.h"
#include "Sequence/Game/GameParent.h"

#include "Image.h"

using namespace GameLib;

namespace Sequence {

Select::Select() {
  mImage = new Image("Image/select.dds");
	mImage->drawScreen();
}

Select::~Select() {
	SAFE_DELETE(mImage);
}

Child* Select::update(Parent* parent) {
	Framework f = Framework::instance();
	Child* next = this;
	if (f.isKeyTriggered('1')) {
		next = new Game::Parent("StageData/stageData1.txt");
	}
	else if (f.isKeyTriggered('2')) {
		next = new Game::Parent("StageData/stageData2.txt");
	}
	return next;
}

}// namespace Sequence 