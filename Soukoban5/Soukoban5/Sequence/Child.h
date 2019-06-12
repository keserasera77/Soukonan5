#pragma once

namespace Sequence {

class Parent;

//シークエンス遷移はクラスにしたほうが使い勝手がよさそう
//Childは全体の制御、Stateはゲームの制御
class Child {
public:
  //Child();
	virtual ~Child(){};
	virtual Child* update(Parent*) = 0;
private:
};

}