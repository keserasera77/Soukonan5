#pragma once

namespace Sequence {

class Child;

class Parent {
public:
  Parent();
	~Parent();

	enum NextSequence {
		NEXT_TITLE,
		NEXT_GAME,
		//NEXT_GAME_OVER,
		NEXT_SELECT,

		NEXT_NONE,
	};
  static Parent* instance();
	static void create();
	static void destroy();
	//void moveTo(NextSequence id);
	void setStageName(const char* filename);
	const char* getStageName() const;
	void update();

private:
	//NextSequence mNextSequence;
  Child* mChild;
  static Parent* mInstance;
	const char* mStageName; 
};

} // namespace Sequence 
