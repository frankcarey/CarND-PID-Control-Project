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

It seemed like `I` didn't really add that much. In fact `I` could have been set to 0 and the resulting PD controller could still get the thing around the track, but adding a little there did help it especially around the corners.

A stronger `P` made the car weave even more (as did adding back a little `I`), but I created a proportional speed controller based on the current CTE.

### Describe how the final hyperparameters were chosen.

As there wasn't really an easy way to automate the car driving around the track to see the total accumulated CTE, I
manually edited the values, changing one at a time similar to the description of the twiddle aglorithm.