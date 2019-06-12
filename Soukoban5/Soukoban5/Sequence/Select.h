#pragma once
#include "Sequence/Child.h"

class Image;

namespace Sequence {

class Parent;

class Select : public Child{
public:
  Select();
	~Select();
	Child* update(Parent* parent);
private:
  Image* mImage;
};

}// namespace Sequence 