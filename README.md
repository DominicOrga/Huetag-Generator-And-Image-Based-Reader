# Huetag Generator and Image-Based Reader

## Description
As part of Huetag's disclosed equipment in its research paper, this project demonstrates the Huetag system's marker identification algorithm and marker generation using its default generator key.

The objectives of this application are limited to:
* Examining the Huetag marker system regarding its marker identification capabilities, particularly when sample images are subjected to various lighting situations.
* Producing sample markers for the aforementioned examination.

**Note: This is not a library for the Huetag system.**

## Standalone Application
Available: "\x64\Debug\Huetag Writer and Image-Based Reader.exe"

## Prerequisites
The project requires the installation of the following software tools:
1. Qt (version 5.9 recommended)
2. OpenCV (version 3.2 recommended)
3. Visual Studio (version 2015 recommended)

## Usage
* Detecting a Huetag from an Image:
  1. Load an image containing a Huetag marker by pressing the 'Browse' button. 
  2. (Optional) Press the 'Update' button to initially show the output image.
  3. Adjust the sliders accordingly to properly detect markers under different lighting conditions. To see their effect, press the 'Update' button. Repeat this step until the Huetag in the image is detected.
      - Binary Threshold. Used for setting the boundaries for the black and white colors.
      - Contour Min Area Threshold. The minimum area allowed for detected contours.
      - Contour Max Area Threshold. The maximum are allowed for detected contours.
      - Kernel Size. Blurring kernel size for reducing noise in an image.
      
      ![read-huetag](https://user-images.githubusercontent.com/12520299/29742382-d7b5ae36-8ab0-11e7-8228-1d1bfd51c27d.gif)
      
* Generating a Huetag:
  1. Press the 'Generate Huetag' button.
  2. Type the desired Huetag ID and press the 'Generate' button. 
  **Note: The key used to produce the marker is Huetag's default generator key.**
  3. To save an image, simply press the 'Save Image' button.
  
      ![generate-huetag](https://user-images.githubusercontent.com/12520299/29742396-18070fde-8ab1-11e7-8833-37a95ce8ef0e.gif)
   
## See Also
Real-Time Huetag Reader Prototype. Available: https://github.com/DominicOrga/Real-Time-Huetag-Reader-Prototype
Huetag Sample Image. Available: https://doi.org/10.6084/m9.figshare.5349934
   
## License
This project is licensed under the MIT License - see the LICENSE.md file for details.
