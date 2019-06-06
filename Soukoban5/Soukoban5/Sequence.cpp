#include "GameLib/Framework.h"
#include "Sequence.h"
#include "File.h"
#include "Image.h"
#include "State.h"

using namespace GameLib;

Sequence::Sequence() : mSequence(SEQUENCE_TITLE), mState(0) {
  mImage = new Image("title.dds");
	drawScreen();
}

void Sequence::doSequence() {
	switch (mSequence) {
	case SEQUENCE_TITLE:
		title();
		break;
	case SEQUENCE_GAME:
		game();
		break;
	case SEQUENCE_SELECT:
		select();
		break;
	case SEQUENCE_LOAD:
		load();
		break;
	case SEQUENCE_CLEAR:
		clear();
		break;
	case SEQUENCE_MENU:
		menu();
		break;
	default:
		cout << "invalid mSequence value" << endl;
		break;
	}
}

void Sequence::drawScreen() {
Framework f = Framework::instance();
	mImage->drawPicture(0,0,0,0,f.width(),f.height());
}

void Sequence::initScreen() {
	Framework f = Framework::instance();
	for (int i = 0; i < f.height() * f.width(); i++) f.videoMemory()[i] = 0x00000000;
}

void Sequence::changeSequence(SequenceID id) {
	Framework f = Framework::instance();

	//画面、画像の初期化
	SAFE_DELETE(mImage);

	mSequence = id;

	switch (id) {
	case SEQUENCE_TITLE:
		mImage = new Image("title.dds");
		drawScreen();
		SAFE_DELETE(mState);
		break;
	case SEQUENCE_GAME:
	  initScreen();
		break;
	case SEQUENCE_SELECT:
		mImage = new Image("select.dds");
		drawScreen();
		SAFE_DELETE(mState);
		break;
	case SEQUENCE_LOAD:
		mImage = new Image("load.dds");
		drawScreen();
		SAFE_DELETE(mState);
		break;
	case SEQUENCE_CLEAR:
		mImage = new Image("clear.dds");
		drawScreen();
		break;
	case SEQUENCE_MENU:
		mImage = new Image("menu.dds");
		drawScreen();
		break;
	default:
		cout << "invalid id value" << endl;
		break;
	}
}

void Sequence::game() {
Framework f = Framework::instance();

if (f.isKeyTriggered(' ')) {
	changeSequence(SEQUENCE_MENU);
	return;
}

mState->update(f.previousFrameInterval());
mState->drawStage();

//ステージクリアーかチェック
if (mState->clearCheck()) {
	cout << "Congratulation!!!" << endl;
	changeSequence(SEQUENCE_CLEAR);
	SAFE_DELETE(mState);
};
}

void Sequence::title() {
	Framework f = Framework::instance();

	if (f.isKeyTriggered(' ')) {
		 changeSequence(SEQUENCE_SELECT);
	}
}

void Sequence::select() {
	Framework f = Framework::instance();

	if (f.isKeyTriggered('1')) {
		mStageName = "stageData1.txt";
		changeSequence(SEQUENCE_LOAD);
	}
	else if (f.isKeyTriggered('2')) {
		mStageName = "stageData2.txt";
		changeSequence(SEQUENCE_LOAD);
	}
}

void Sequence::load() {
	Framework f = Framework::instance();

	if (!mState) {
		//ステージの読み込み
		File stage(mStageName);
		if (!stage.data()) {
			cout << "stagefile could not be read";
			return;
		}
		mState = new State(stage.data(), stage.size());
		changeSequence(SEQUENCE_GAME);
		mState->drawStage();
		return;
	}
	f.sleep(1000);
}

void Sequence::clear() {
	Framework f = Framework::instance();

	if (f.isKeyTriggered(' ')) {
		changeSequence(SEQUENCE_TITLE);
	}
}

void Sequence::menu() {
	Framework f = Framework::instance();
	if (f.isKeyTriggered('1')) {
		changeSequence(SEQUENCE_LOAD);
		//SAFE_DELETE(mState);
	}
	else if (f.isKeyTriggered('2')) {
		changeSequence(SEQUENCE_SELECT);
		//SAFE_DELETE(mState);
	}
	else if (f.isKeyTriggered('3')) {
		changeSequence(SEQUENCE_TITLE);
		//SAFE_DELETE(mState);
	}
	else if (f.isKeyTriggered('4')) {
		changeSequence(SEQUENCE_GAME);
	}
}

