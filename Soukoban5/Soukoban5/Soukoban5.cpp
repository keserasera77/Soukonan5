//Stateのメンバ変数mPx,mPyや、gCellEdgeを用いている点がサンプルコードと違う。

#include "GameLib/Framework.h"
#include <iostream>
#include "Image.h"
#include "File.h"
#include "State.h"
#include "Sequence.h"

using namespace GameLib;

Sequence* gSequence = 0;
int gCount = 0; //mainLoopのループ数

enum SequenceID {
	SEQUENCE_TITLE,
	SEQUENCE_GAME,
	SEQUENCE_SELECT,
	SEQUENCE_LOAD,
	SEQUENCE_CLEAR,
	SEQUENCE_MENU
};

namespace GameLib {
	void Framework::update() {
	Framework f = Framework::instance();
	 instance().sleep(1); //少しは寝かせる

	//フレームレート計測
	 unsigned currentTime = f.time();
	 if (gCount % 60 == 0) cout << "frameRate :: " << f.frameRate() << " (fps)" << endl;
	 gCount++;
	 //f.setFrameRate(60) // 固定フレームレート

	 if (!gSequence) {
		 gSequence = new Sequence; 
	 }

	 //終了
	 if (f.isKeyOn('q')) {
		 f.requestEnd();
	 }

	 if (f.isEndRequested()) {
		 SAFE_DELETE(gSequence);
		 return;
	 }

	 gSequence->doSequence();
	 }
}

