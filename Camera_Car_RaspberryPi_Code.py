import cv2 # OpenCV for camera and face detection
import serial # For USB communication with Arduino
import time # For small delays

arduino = serial.Serial('/dev/ttyACM0', 9600) #Communicates with the Pi USB port at 9600 baud
time.sleep(2) # Wait for Arduino to initialize

#This loads a Haar Cascade model, making face_cascade a python object that can be used to detect objects in images.
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

# Open the webcam (index 0)
cam = cv2.VideoCapture(0)

#This variable stores the smoothed horizontal face movement.
smooth_x = 0

# Set resolution 
cam.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cam.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

while True:
    ret, frame = cam.read()  # Capture frame
    
    if not ret:
        print("Cannot read frame")
        break

    # Convert image to grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    
    # Detect faces
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5) 

    for (x, y, w, h) in faces:
        # Draw rectangle
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)

        # Find center of the face
        face_center_x = x + w // 2

        # Find center of the frame
        frame_center_x = frame.shape[1] // 2

        # Calculate horizontal movement
        offset_x = face_center_x - frame_center_x   # "+" --> right, "-" --> left

        # Smooth the movement
        smooth_x = 0.8 * smooth_x + 0.2 * offset_x

        # Movement b sends one byte over serial
        if smooth_x > 50:
            arduino.write(b'r') # Turn Right
        elif smooth_x < -50:
            arduino.write(b'l') # Turn Left
        else:
            arduino.write(b'f') # Move Forward
            
    if len(faces) == 0:
        arduino.write(b's') # Stop the motors

    # Show the camera view
    cv2.imshow("Camera View", frame)

    # Quit with 'q'
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()
