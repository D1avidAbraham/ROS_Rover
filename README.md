# ROS_Rover

# Differential-drive robot (DDR)
There are only two axis that this robot can move, the x-axis and the y-axis. 
The x-axis aligns with the forward motion of the robot and the y-axis aligns with the axis of wheel rotation. 

A configuration space, denoted by $q$ specifies the locations on the robot.

### Inverse Velocity Kinematics Equations for DDR

$\theta_{left} = \dfrac{v_x}{r} - \dfrac{L}{2}\dfrac{\omega}{r}$<br>
$\theta_{right} = \dfrac{v_y}{r} + \dfrac{L}{2}\dfrac{\omega}{r}$


$L$ = distance between the two wheels <br>
$r$ = raduis of the wheel <br>
$v$ = linear velocity <br>
$\omega$ = angular velocity <br>

Give the desired Linear and angular velocity is will give back the angular distance the DC motor has to travel 

### Inverse Velocity Kinematics Equations For Tread drivetrain

<table>
  <tr>
    <th>Parameter</th>
    <th>Symbol</th>
    <th>Units</th>
  </tr>
  <tr>
    <td>Desired forward speed</td>
    <td>Desired yaw rate</td>
    <td>Half the distance between the two treads</td>
    <td>Left-tread linear speed</td>
    <td>Right-tread linear speed</td>
    <td>Tread wheel radius</td>
    <td>Left wheel angular speed</td>
    <td>Right wheel angualr speed</td>

  </tr>
  <tr>
    <td>Centro comercial Moctezuma</td>
    <td>Francisco Chang</td>
    <td>Mexico</td>
  </tr>
</table>



# Reference 
1. https://www.roboticsbook.org/S51_diffdrive_state.html