#include "GameLib/GameLib.h"
#include "Sequence/Parent.h"
#include "Sequence/Title.h"
#include "Sequence/Select.h"
#include "Sequence/Game/GameParent.h"
#include "Sequence/Game/GameChild.h"
#include "Sequence/Game/Load.h"

namespace Sequence {
namespace Game {

//SelectからLoadへ行くパターン
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
  //Sequence::Childの派生クラスとしての役割
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

	//Game::Parentとしての役割
	Game::Child* nextChild = mChild->update(this);

	if (nextChild != mChild) {
		SAFE_DELETE(mChild);
		mChild = nextChild;
	}

	return nextParent; //Sequence::Childの派生クラスとしての役割
}

void Parent::moveTo(NextSequence next) {
 mNextSequence = next;
}


}//	namespace GameLib 
}// namespace Sequence 