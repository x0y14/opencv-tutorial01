#include <iostream>
#include "opencv2/opencv.hpp"
#include <fstream>


int main() {
    // show build information
    std::cout << cv::getBuildInformation() << std::endl;

    std::cout << "start create video" << std::endl;
    // define output-video's format
    int fourcc = cv::VideoWriter::fourcc('m', 'p', '4', 'v');

    // output = {fps=60, duration=5sec}
    // setup output video
    cv::VideoWriter output(
            "tutorial-video.mp4",
            fourcc,
            60,
            cv::Size(1920, 1080),
            true);

    // output is opened?
    if (!output.isOpened()) {
        // error
        std::cout << "cant open output file" << std::endl;
        return 1;
    }

    // setup text font
    cv::FontFace fontFace("Roboto-Regular.ttf");

    // setup white mat for video
    cv::Mat canvas(1080, 1920, CV_8UC3, cv::Scalar(255,255,255));

    // output = {fps=60, duration=5sec}
    for (int i=0; i<60*5; i++) {
        // clone main canvas-mat (無駄?)
        cv::Mat clone = canvas.clone();
        // write text
        cv::putText(
                clone, std::to_string(i),
                cv::Point(1920/2, 1080/2),
                cv::Scalar::all(0),
                fontFace,
                25);
        // write mat to video
        output << clone;
    }

    std::cout << "end create video" << std::endl;
    return 0;
}
