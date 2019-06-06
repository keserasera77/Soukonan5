#pragma once

class Image;
class State;

//�V�[�N�G���X�J�ڂ̓N���X�ɂ����ق����g�����肪�悳����
//Sequence�͑S�̂̐���AState�̓Q�[���̐���
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
