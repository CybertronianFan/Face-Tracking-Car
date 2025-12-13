# Autonomous Face Tracking Rover



This repository outlines the process of my making a rover, which follows faces. This works by the Raspberry Pi tracking faces using a Haar Cascade model and communicating to the Arduino to move the motors accordingly based off of the face's horizontal offset from the webcam. Make sure to follow all of the steps.



By CybertronianFan on GitHub. Please do not take my work without asking.



Components I used (Some of these can be substituted for other appropriate components):

* 4 DC gear motors
* 4 wheels for the gear motors
* Arduino Uno
* DFRobot Quad Motor Driver Shield for Arduino Uno
* Raspberry Pi 3 Model B+
* 2 18650 Batteries
* 18650 Battery holder
* Logitech C270
* A power bank or portable power source for the Raspberry Pi
* Cardboard for the rover chassis/shell + some way to connect the components (I used zip ties)





Set-up Guidance:

* Make a project folder on the Raspberry Pi with the files you must download labelled "FaceTrackingCode\_RaspberryPi" and the file labelled "haarcascade\_frontalface\_default"





Building Guidance:

* Make sure that the carboard box is flat so all the wheels are level.
* Make sure the webcam is on the front of the rover.
* The gear motors should all be facing forwards with the part that the wheels attach to sticking out of a hole of the box.
* Connect the top left motor to M1, top right to M2, bottom left to M3, bottom right to M4.
* The power bank should be giving power to the Raspberry Pi, which will be giving power via USB to the Arduino Uno.
* Note that the batteries should be powering the driver shield.





Coding Guidance:

* Use the code from "MotorCode\_Arduino" and transfer it to the Arduino using Arduino IDE using the Raspberry Pi or a desktop/laptop.
* Make sure Python 3 is installed on the Raspberry Pi. (You may have to change the version if OpenCV is not working - I used python 3.13.11)
* Make sure OpenCV is installed on the Raspberry Pi.
* Install pip.
* With the Arduino unplugged from the Raspberry Pi, type "ls /dev/tty\*" and it will list the different ports. Then do the same with the Arduino plugged in. **There will be one extra and that will be put in place of "ACM0" in line 5. Without this step there is a high chance of the program not working.**
* Copy the code from "FaceTrackingCode\_RaspberryPi" into an IDE such as Thonny (on the Raspberry Pi) and run it with the Arduino plugged in. After this unplug the Raspberry Pi from the monitor and other peripherals.
* Make sure all of the components are connected properly and the rover will work.
