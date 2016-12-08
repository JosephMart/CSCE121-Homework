#include <iostream>
#include <vector>
#include "Viewer.h"

using namespace std;

void buttonCallback(Fl_Widget* widget, void* viewerPtr) {
	Viewer* viewer = static_cast<Viewer*>(viewerPtr);
	viewer->navPressed(widget);
	/* you can name this whatever you want, the idea is to call a
	     member function in the viewer class that does what is needed
	     to update the image. You'll pass in the widget (you can also
	     dynamic cast it to a NavButton before passing it). From the
	     widget the function can determine whether to move forward
	     or backward in the list.
	*/
}

Viewer::Viewer(string imageFolder, vector<string> imageFilenames, int width = 800, int height = 600) :
	Fl_Window(width, height, "Image Viewer"), imageFolder(imageFolder), imageFilenames(imageFilenames), currentIndex(0),
	prev(nullptr), next(nullptr), imageBox(nullptr), pic(nullptr) {
  	prev = new NavButton(getPathFilename(imageFilenames.at(imageFilenames.size()-1), true),
		"Previous Button",
		borderSize,
		this->h() - borderSize - thumbnailSize - borderSize,
		thumbnailSize, imageFilenames.size() - 1);
	next = new NavButton(getPathFilename(imageFilenames.at((imageFilenames.size()+1)%imageFilenames.size()), true),
		"Next Button",
		this->w() - borderSize - thumbnailSize - borderSize,
		this->h() - borderSize - thumbnailSize - borderSize,
		thumbnailSize, imageFilenames.size()-1);
	imageBox = new Fl_Box(borderSize,
		borderSize,
		this->w() - (2*borderSize),
		this->h() - (2*borderSize) - thumbnailSize - 2*borderSize);
	//imageBox->box(FL_BORDER_BOX); // useful to see where the full size of the widget holding the images
	prev->callback(buttonCallback,static_cast<void*>(this));
	next->callback(buttonCallback,static_cast<void*>(this));

	pic = new Fl_JPEG_Image(getPathFilename(imageFilenames.at(currentIndex)).c_str());
	imageBox->image(pic);
	this->end();
}

string Viewer::getPathFilename(string filename, bool thumb) {
	string thumbPart = "";
	if (thumb) thumbPart = "t_";
	return imageFolder + "/" + thumbPart+ filename;
}

void Viewer::navPressed(Fl_Widget* widget) {
	NavButton* button = static_cast<NavButton*>(widget);
	int nPic = 0;
	int pPic = 0;

	if (button->getLabel() == "Next Button") {
		if (currentIndex+1 == imageFilenames.size()) {
			currentIndex = 0;
			pPic = imageFilenames.size() - 1;
			nPic = 1;
		} else if (currentIndex + 2 == imageFilenames.size()) {
			currentIndex++;
			pPic = currentIndex - 1;
			nPic = 0;
		} else {
			currentIndex++;
			pPic = currentIndex - 1;
			nPic = currentIndex + 1;
		}
	} else if (button->getLabel() == "Previous Button") {
		if (currentIndex-1 == 0) {
			currentIndex = 0;
			pPic = imageFilenames.size() - 1;
			nPic = 1;
		} else if (currentIndex - 1 < 0) {
			currentIndex = imageFilenames.size() - 1;
			pPic = currentIndex - 1;
			nPic = 0;
		} else {
			currentIndex--;
			pPic = currentIndex - 1;
			nPic = currentIndex + 1;
		}
	}

	std::cout << currentIndex << '\n';
	nextPic = new Fl_JPEG_Image(getPathFilename(imageFilenames.at(nPic), true).c_str());
	prevPic = new Fl_JPEG_Image(getPathFilename(imageFilenames.at(pPic), true).c_str());
	pic = new Fl_JPEG_Image(getPathFilename(imageFilenames.at(currentIndex)).c_str());

	prev->image(prevPic);
	next->image(nextPic);
	imageBox->image(pic);
	this->redraw();
}
