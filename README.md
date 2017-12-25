PID Controller
==============


Full video can be found [here](https://vimeo.com/246631329)


Reflection
-----------

### Describe the effect each of the P, I, D components had in your implementation.

The final PID settings that worked were:
```
P: .05
I: .002
D: 12.0;
```

`P`, or the "proportional" part of the controller made the car steer into the center line in proportion to the CTE or cross-track error. The downside is that it causes the car to weave a lot when it's the only component.

`I`, or the "integral" part of the controller made the car steer into the center line proportial to the integral of the CTE or cross-track error. That means as the CTE accumulates between update steps, the I portion will increase, steering with more and more of an angle until it crosses the center line and then the negative CTE starts to reduce it. What was interesting was that the error could accumulate rapidly, overwhelming other components of the controller.

`D` or the "derivative" part of the controller tracks the change in the CTE from one timestep to the next. When the CTE is increasing, it causes the car to steer more steeply in the opposite direction, but when CTE is decreasing it causes the car to steer away from the center line, helping to smooth out the weaving that we see caused by the `P` and `I` components.


### Describe how the final hyperparameters were chosen.

As there wasn't really an easy way to automate the car driving around the track to see the total accumulated CTE, I
manually edited the values, changing one at a time similar to the description of the twiddle aglorithm.

In my final settings, it seemed like `I` didn't really add that much. In fact `I` could have been set to 0 and the resulting PD controller could still get the car around the track, but adding a little there did help it especially around the corners. Having a higher `I` really hurt things though because as mentioned above, the total error could build up quickly and overwhelm the other components.

A stronger `P` made the car weave even more (as did adding back a little `I`)