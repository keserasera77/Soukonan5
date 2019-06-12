// Sequence -> Child, Parent
//drawScreenをImageクラスに移動
//第10章のシークエンス遷移も参考にした(クラスの継承を利用した方法)

#include "GameLib/Framework.h"
#include <iostream>
#include "State.h"
#include "Sequence/Parent.h"

using namespace GameLib;

int gCount = 0; //mainLoopのループ数

namespace GameLib {
	void Framework::update() {
	Framework f = Framework::instance();

	f.sleep(1); //少しは寝かせる

	//フレームレート計測
	 unsigned currentTime = f.time();
	 if (gCount % 60 == 0) cout << "frameRate :: " << f.frameRate() << " (fps)" << endl;
	 gCount++;
	 //f.setFrameRate(60) // 固定フレームレート

	 if (!Sequence::Parent::instance()) {
		 Sequence::Parent::create();
	 }

	 //終了
	 if (f.isKeyOn('q')) {
		 f.requestEnd();
	 }

	 if (f.isEndRequested()) {
		 Sequence::Parent::destroy();
		 return;
	 }

	 Sequence::Parent::instance()->update();
	 }
}

