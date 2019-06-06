#pragma once

class Image;
class State;

//シークエンス遷移はクラスにしたほうが使い勝手がよさそう
//Sequenceは全体の制御、Stateはゲームの制御
class Sequence {
public:
  Sequence();
	//~Sequence();
	enum SequenceID {
		SEQUENCE_TITLE,
		SEQUENCE_GAME,
		SEQUENCE_SELECT,
		SEQUENCE_LOAD,
		SEQUENCE_CLEAR,
		SEQUENCE_MENU
	};
	void doSequence();
	void changeSequence(SequenceID id);
private:
	SequenceID mSequence = SEQUENCE_TITLE;
	Image* mImage;
	const char* mStageName;
	State* mState;
	void drawScreen();
	void initScreen();
	void game();
	void title();
	void select();
	void load();
	void clear();
	void menu();
};
