#pragma once
#include "Sequence/Game/GameChild.h"

class Image;
class Parent;

namespace Sequence {
	namespace Game {

class Load : public Child{
public:
  Load();

  Child* update(Parent*);

private:
  Image* mImage;
};

 }// namespace Game
}// namespace Sequence