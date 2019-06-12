#include "Sequence/Child.h"

class State;

namespace Sequence {
class Parent;
namespace Game {

class Child;

class Parent : public Sequence::Child {
public:
	Parent(const char* filename);
	//~Parent();
	enum NextSequence {
		NEXT_TITLE,
		NEXT_SELECT,

		NEXT_LOAD,
		NEXT_MENU,
		NEXT_GAME,
		NEXT_CLEAR,

		NEXT_NONE
	};

	const char* getStageName() const;
	Child* update(Sequence::Parent*);
	void moveTo(NextSequence);
	void setState(State* state);
	State* getState();

private:
	NextSequence mNextSequence;
	Game::Child* mChild;
	const char* mStageName;
	State* mState;
};

}// namespace Sequence 
}//	namespace GameLib 

