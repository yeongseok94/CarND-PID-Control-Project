# Model Description

This documentation describes the PID control module designed for this project.

## Effect of PID gains

### P gain

P gain helps fast convergence of the error in the first place (decreases rising time) but excessive P gain causes overshoot of the system.
In this project, the lateral response of the vehicle was highly sensitive to P gain.

### I gain

I gain helps reducing steady state error of the response, and has some smoothing effect.
However, too much I gain would increase integral term of error and let the system diverge.
Thus, typical usage of I gain is to use very small gain and use with forgetting factor which is multiplied with previous step's integral term.

### D gain

D gain helps reducing excessive rising or falling of the response, in other words, helps smoothing.
However, in digital control system like this project, D gain also has effect something like P gain.
Therefore, excessive D gain again gives oscillating effect, which is a property when D gain is 0.

## Selection of PID gain

Final selection of PID gains and the forgetting factor is:

* Kp = 0.02
* Ki = 0.02
* Kd = 2.0
* forgetting factor = 0.9

### Gain Tuning Procedure

1. First, select proper Kp that makes the car follow the track even though it has a lot of oscillation.
2. Next, select Kd that has sufficient amount of smoothing effect and does not make oscillation again. In this procedure, also finetune Kp when needed.
3. Finally, using Ki and proper forgetting factor, again finetune the response. I this project, this procedure really helped finetuing the response since the reference trajectory has many sharp edges which makes sudden changes on the steering angle and CTE.

## Final Video

Full simulation video: [Link](./finalvideo.mp4)