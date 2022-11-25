#include "SoundD.h"

SoundD::SoundD() {
	
}

SoundD::~SoundD() {

}

void SoundD::BGM() {
	if (!this->BGMusic.openFromFile("lavenderTheme.ogg")) {
		std::cout << "Error Music BGM" << std::endl; // error
	}
	BGMusic.play();
	BGMusic.setLoop(true);
}
