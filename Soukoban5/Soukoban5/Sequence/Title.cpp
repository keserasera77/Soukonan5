#include "GameLib/Framework.h"
#include "Image.h"
#include "Sequence/Parent.h"
#include "Sequence/Title.h"
#include "Sequence/Select.h"

using namespace GameLib;

namespace Sequence {

Title::Title() {
	mImage = new Image("Image/title.dds");
	mImage->drawScreen();
}

Title::~Title() {
	SAFE_DELETE(mImage);
}

Child* Title::update(Parent* parent) {
  Child* next = this;
	Framework f = Framework::instance();

	if (f.isKeyTriggered(' ')) {
		next = new Select;
	}

	return next;
}

}// namespace Sequence {