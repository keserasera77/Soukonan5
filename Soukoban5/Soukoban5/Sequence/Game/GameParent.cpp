#include "GameLib/GameLib.h"
#include "Sequence/Parent.h"
#include "Sequence/Title.h"
#include "Sequence/Select.h"
#include "Sequence/Game/GameParent.h"
#include "Sequence/Game/GameChild.h"
#include "Sequence/Game/Load.h"

namespace Sequence {
namespace Game {

//Select����Load�֍s���p�^�[��
Parent::Parent(const char* filename) : mNextSequence(NEXT_NONE), mState(0) {
  mChild = new Load();
  mStageName = filename;
}

const char* Parent::getStageName() const{
	return mStageName;
}

void Parent::setState(State* state) {
  SAFE_DELETE(mState);
	mState = state;
}
State* Parent::getState() {
	return mState;
}

Sequence::Child* Parent::update(Sequence::Parent* parent) {
  //Sequence::Child�̔h���N���X�Ƃ��Ă̖���
	Sequence::Child* nextParent = this;
	switch (mNextSequence) {
	case NEXT_TITLE:
	  nextParent = new Title;
		break;
	case NEXT_SELECT:
	  nextParent = new Select;
		break;
	default:
	  break;
	}

	//Game::Parent�Ƃ��Ă̖���
	Game::Child* nextChild = mChild->update(this);

	if (nextChild != mChild) {
		SAFE_DELETE(mChild);
		mChild = nextChild;
	}

	return nextParent; //Sequence::Child�̔h���N���X�Ƃ��Ă̖���
}

void Parent::moveTo(NextSequence next) {
 mNextSequence = next;
}


}//	namespace GameLib 
}// namespace Sequence 