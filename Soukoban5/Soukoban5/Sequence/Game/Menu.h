#pragma once
#include "Sequence/Game/GameChild.h"

class Image;

namespace Sequence {
namespace Game {

class Menu : public Child {
public:
  Menu();
	//~Menu();
	Child* update(Parent*);
private:
  Image* mImage;
};

}// namespace Game
}// namespace Sequence