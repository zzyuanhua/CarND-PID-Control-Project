
# PID Control Project

## Implementation

Two PID controls  are implemented,one control steer,another control throttle.

## Reflection

P : proportion to the cross track error.

I :  the weight of system bias in the cross track error. I recorded sum of 25 steps cte.

D : the weight of the cte diffence.

## Describe how the final hyperparameters were chosen.

The PID final hyperparameters  are 0.22, 0.01, 30 .Those hyperparameters simultaneously are used to control both steer and throttle.
The parameters of pid  could be have been done through manual tuning.when Turns change too much，I increase the Kd value.when vehicle biased,increasing the Ki value.
