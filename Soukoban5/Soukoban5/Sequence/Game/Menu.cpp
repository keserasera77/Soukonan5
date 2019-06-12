#include "GameLib/Framework.h"
#include "Sequence/Game/GameParent.h"
#include "Sequence/Game/Load.h"
#include "Sequence/Game/Game.h"
#include "Sequence/Game/Menu.h"

#include "Image.h"

using namespace GameLib;

class Image;

namespace Sequence {
namespace Game {

Menu::Menu() {
  mImage = new Image("Image/menu.dds");
	mImage->drawScreen();
}

Child* Menu::update(Parent* parent) {
	Framework f = Framework::instance();
	Child* next = this;
	if (f.isKeyTriggered('1')) {
	  next = new Game;
		parent->initState();
		//SAFE_DELETE(mState);
	}
	else if (f.isKeyTriggered('2')) {
		parent->moveTo(Parent::NEXT_SELECT);
		//SAFE_DELETE(mState);
	}
	else if (f.isKeyTriggered('3')) {
		parent->moveTo(Parent::NEXT_TITLE);
		//SAFE_DELETE(mState);
	}
	else if (f.isKeyTriggered('4')) {
		next = new Game;
	}
	return next;
}
}// namespace Game
}// namespace Sequence