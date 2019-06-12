#pragma once
#include "Sequence/Child.h"

class Image;
class Parent;

namespace Sequence {

class Title : public Child {
public:
  Title();
	~Title();
  
	Child* update(Parent*);
private:
 Image* mImage;

};

}// namespace Sequence 