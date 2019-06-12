#include "GameLib/Framework.h"
#include "Sequence/Game/Game.h"
#include "Sequence/Game/Load.h"
#include "Sequence/Game/GameParent.h"
#include "State.h"
#include "File.h"
#include "Image.h"

using namespace GameLib;

namespace Sequence {
namespace Game {

Load::Load() {
  mImage = new Image("Image/load.dds");
	mImage->drawScreen();
}

Child* Load::update(Parent* parent) {
  Child* next = this;
	Framework f = Framework::instance();

	//�X�e�[�W�̓ǂݍ���
	File stage(parent->getStageName());
	if (!stage.data()) {
		cout << "stagefile could not be read";
		return next;
	}
	parent->setState(new State(stage.data(), stage.size()));
	next = new Game;
	return next;

	f.sleep(1000);//�l�q��
}

}// namespace Game
}// namespace Sequence