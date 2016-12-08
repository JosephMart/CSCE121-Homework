#include <iostream>
#include <string>
#include "NavButton.h"
#include "Viewer.h"
using namespace std;

NavButton::NavButton(string imageFilename, string label, int x, int y, int thumbnailsize, int imageIndex, const char *L) :
	Fl_Button(x, y, 1, 1, L), clickCount(0), label(label), thumbnailsize(thumbnailsize), imageLabel(nullptr) {
	setImage(imageFilename);
}

string NavButton::getLabel() const {
	return label;
}

void NavButton::setImage(string filename) {
	delete imageLabel;
	imageLabel = new Fl_JPEG_Image(filename.c_str());
	imageLabel->copy(thumbnailsize, thumbnailsize);
	image(imageLabel);
	this->resize(this->x(), this->y(), thumbnailsize + Viewer::borderSize, thumbnailsize + Viewer::borderSize);
}

int NavButton::totalClicks = 0;


int NavButton::handle(int event){

     switch(event) {

    	case FL_RELEASE:
			pressed();
			this->do_callback();
      		return 1;

		case FL_KEYUP:
			// cout << Fl::event_key() << '\n';
			if (Fl::event_key() == 65363 || Fl::event_key() == 110 || Fl::event_key() == 65289 ) {
				if (label == "Next Button") {
					pressed();
					this->do_callback();
					return 1;
				}
			} else if(Fl::event_key() == 65361 || Fl::event_key() == 112 || Fl::event_key() == 65288) {
				if (label == "Previous Button") {
					pressed();
					this->do_callback();
					return 1;
				}
			}
    	default:
      		return Fl_Widget::handle(event);
  	}

}

void NavButton::pressed(){
	clickCount++;
	totalClicks++;
	std::cout << "The " << label << " button has been pressed " << clickCount << " times." << '\n';
	std::cout << "All buttons have been pressed " << totalClicks <<" times" << '\n' << '\n';
}
