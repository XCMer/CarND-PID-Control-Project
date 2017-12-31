# Parameter tuning for the PID controller

One of the mentors had posted an approach to finding the right hyperparameters: https://discussions.udacity.com/t/car-veering-off/312738/11

Combining that intuition, I decided to do twiddle manually. I'll start with one parameter at a time, and then see how far the car is able to go without veering off.

## Optimizing Kp

### Kp=0.1
I started with Kp=0.1, and the other two parameters set to 0. The car starts off normal, but by the name it reaches the first curve, it starts oscillating, and eventually going off road.

Video: [Kp=0.1, Ki=0, Kd=0](videos/Kp1.mp4)

### Kp=0.2

To get a feel for what happens when I increase Kp, I set it to 0.2. This time, the car start veering off sooner.

Video: [Kp=0.2, Ki=0, Kd=0](videos/Kp2.mp4)




