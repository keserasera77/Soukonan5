#pragma once

namespace Sequence {

class Parent;

//�V�[�N�G���X�J�ڂ̓N���X�ɂ����ق����g�����肪�悳����
//Child�͑S�̂̐���AState�̓Q�[���̐���
class Child {
public:
  //Child();
	virtual ~Child(){};
	virtual Child* update(Parent*) = 0;
private:
};

}