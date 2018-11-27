#include<iostream>


//The code below shows the Image interface representing the Subject.The interface has a single method showImage() 
//that the Concrete Images must implement to render an image to screen.

class Image {
public:
	virtual void showImage() = 0;
};


//The code below displays the RealSubject Implementation, which is the concrete and heavyweight 
//implementation of the image interface.The High resolution image, loads a high resolution image 
//from disk, and renders it to screen when showImage() is called.

/**
* RealSubject
*/
class HighResolutionImage : public Image {
public:

	HighResolutionImage(std::string imageFilePath) {

		loadImage(imageFilePath);
	}

	void loadImage(std::string imageFilePath) {

		// load Image from disk into memory
		// this is heavy and costly operation
	}

	//@Override
	void showImage() {

		// Actual Image rendering logic

	}

};


//The code below shows the Proxy implementation, the image proxy is a virtual proxy that creates and loads 
//the actual image object on demand, thus saving the cost of loading an image into memory until it needs to
//be rendered :
class ImageProxy : public Image {

	/**
	* Private Proxy data
	*/
	std::string imageFilePath;

	/**
	* Reference to RealSubject
	*/
	Image *proxifiedImage;

public:
	ImageProxy(std::string imageFilePath) {
		this->imageFilePath = imageFilePath;
	}

	
	void showImage() {

		// create the Image Object only when the image is required to be shown

		proxifiedImage = new HighResolutionImage(imageFilePath);

		// now call showImage on realSubject
		proxifiedImage->showImage();

	}

};

//The code below illustrates a sample image viewer program; the program simply loads three images, 
//and renders only one image, once using the proxy pattern, and another time directly.Note that 
//when using the proxy pattern, although three images have been loaded, the High resolution image 
//is not loaded into memory until it needs to be rendered, while in the part not using the proxy, 
//the three images are loaded into memory although one of them is actually rendered.


int main() {

	// assuming that the user selects a folder that has 3 images	
	//create the 3 images 	
	Image *highResolutionImage1 = new ImageProxy("sample/veryHighResPhoto1.jpeg");
	Image *highResolutionImage2 = new ImageProxy("sample/veryHighResPhoto2.jpeg");
	Image *highResolutionImage3 = new ImageProxy("sample/veryHighResPhoto3.jpeg");

	// assume that the user clicks on Image one item in a list
	// this would cause the program to call showImage() for that image only
	// note that in this case only image one was loaded into memory
	highResolutionImage1->showImage();

	// consider using the high resolution image object directly
	Image *highResolutionImageNoProxy1 = new HighResolutionImage("sample/veryHighResPhoto1.jpeg");
	Image *highResolutionImageNoProxy2 = new HighResolutionImage("sample/veryHighResPhoto2.jpeg");
	Image *highResolutionImageBoProxy3 = new HighResolutionImage("sample/veryHighResPhoto3.jpeg");


	// assume that the user selects image two item from images list
	highResolutionImageNoProxy2->showImage();

	// note that in this case all images have been loaded into memory 
	// and not all have been actually displayed
	// this is a waste of memory resources

}

