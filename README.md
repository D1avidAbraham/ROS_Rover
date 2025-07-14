# ROS_Rover

# Differential-drive robot (DDR)
There are only two axis that this robot can move, the x-axis and the y-axis. 
The x-axis aligns with the forward motion of the robot and the y-axis aligns with the axis of wheel rotation. 

A configuration space, denoted by $q$ specifies the locations on the robot.

### Inverse Velocity Kinematics Equations

$\theta_{left} = \dfrac{v_x}{r} - \dfrac{L}{2}\dfrac{\omega}{r}$<br>
$\theta_{right} = \dfrac{v_y}{r} + \dfrac{L}{2}\dfrac{\omega}{r}$


$L$ = distance between the two wheels <br>
$r$ = raduis of the wheel <br>
$v$ = linear velocity <br>
$\omega$ = angular velocity <br>



# Reference 
1. https://www.roboticsbook.org/S51_diffdrive_state.html