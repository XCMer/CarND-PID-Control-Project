# PID Controller

One of the mentors had posted an approach to finding the right hyperparameters: https://discussions.udacity.com/t/car-veering-off/312738/11

Combining that intuition, I decided to do twiddle manually. I'll start with one parameter at a time, and then see how far the car is able to go without veering off.

## Parameter tuning

### Optimizing Kp

#### Kp=0.1
I started with Kp=0.1, and the other two parameters set to 0. The car starts off normal, but by the name it reaches the first curve, it starts oscillating, and eventually going off road.

Video: [Kp=0.1, Ki=0, Kd=0](videos/Kp1.mp4)

#### Kp=0.2

To get a feel for what happens when I increase Kp, I set it to 0.2. This time, the car start veering off sooner.

Video: [Kp=0.2, Ki=0, Kd=0](videos/Kp2.mp4)

Kp is responsible for making sudden changes. Too low of a value means the car will never recover. Kd can be used to control the oscillating behavior of Kp. So I decided to keep Kp at 0.2.

### Optimizing Kd

#### Kd=0.5

I started with a small value to see if it has any influence. This time, the car survived the first turn, but was still oscillating. Increasing Kd like in the twiddle algorithm seemed to be the right move forward.

Video: [Kp=0.2, Ki=0, Kd=0.5](videos/Kd1.mp4)

#### Kd=1.0

Next, I set Kd to 1.0 to test how it works this time. There were not a lot of oscillations in the initial part of the track, but they got pretty noticeable near the bridge.

Video: [Kp=0.2, Ki=0, Kd=1.0](videos/Kd2.mp4)

#### Kd=2.0

Since increasing Kd brought improvement, this time I decided to increase it to 2.0. The intent was to check if it solves the oscillations at the bridge. It did reduce it, but I thought I could increase Kd further.

Video: [Kp=0.2, Ki=0, Kd=2.0](videos/Kd3.mp4)

#### Kd=3.0

I increase Kd to 3.0. This time, the car was pretty stable at the bridge. I decided to conclude optimising Kd.

Video: [Kp=0.2, Ki=0, Kd=3.0](videos/Kd4.mp4)

### Optimizing Ki

#### Ki=0.1

I started, in retrospect, with too large a value for Ki. The error accumulated so quickly that the car went outside the road almost immediately.

Video: [Kp=0.2, Ki=0.1, Kd=3.0](videos/Ki1.mp4)

#### Ki=0.01

I reduced Ki by a factor of 10, bringing it to 0.01. There were still problems, and the car went off the road again.

Video: [Kp=0.2, Ki=0.01, Kd=3.0](videos/Ki2.mp4)

#### Ki=0.001

Reducing again by a factor of 10, I set Ki to 0.001. The car gained slight oscillations at the beginning, but was stable overall. I feel that Ki didn't add much to the stability, but I still left it intact at 0.001. I think this is primarily because I programmed Ki to be cumulative over all errors. Adding a window, i.e., considering only the last `n` errors could help, but `n` also becomes a hyperparameter that we'd need to optimize.

Video: [Kp=0.2, Ki=0.001, Kd=3.0](videos/Ki3.mp4)

## Effect of PID components

### P

With increase in P, the magnitude of oscillations increased. I had expected this to happen. It's important to not keep P so small that it takes a long time to recover from errors.

### D

To counteract the oscillating tendencies of P, I added D. Choosing a large value for D (3.0 in my case) ensured that the corrections were smooth, and no sudden turns were made.

### I

Choosing a significant value caused the errors to accumulate very quickly, veering the car off the road. Smaller values obviated this problem, but didn't end up contributing a lot because of the lack of bias. One optimization that I could think of was to only integrate values from a certain amount of past time-steps instead of all of them. I did not implement it in this project.

## Final video

The final video (till the bridge) is below:

Final Video: [Kp=0.2, Ki=0.001, Kd=3.0](videos/Ki3.mp4)
