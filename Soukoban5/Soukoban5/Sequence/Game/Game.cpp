#include "GameLib/Framework.h"
#include "State.h"
#include "Sequence/Game/Game.h"
#include "Sequence/Game/GameParent.h"
#include "Sequence/Game/Menu.h"
#include "Sequence/Game/Clear.h"

using namespace GameLib;

namespace Sequence {
namespace Game {

Game::Game() {
  Framework f = Framework::instance();
  for (int i = 0; i < f.height()*f.width(); i++) f.videoMemory()[i] = 0;
}

Game::~Game() {
}

Child* Game::update(Parent* parent) {
	Framework f = Framework::instance();
	Child* next = this;

	if (f.isKeyTriggered(' ')) {
		next = new Menu;
		return next;
	}

	parent->getState()->update(f.previousFrameInterval());
	parent->getState()->drawStage();

	//ステージクリアーかチェック
	if (parent->getState()->clearCheck()) {
		cout << "Congratulation!!!" << endl;
		next = new Clear;
	};

	return next;
}

}// namespace Game 
}// namespace Sequence 
