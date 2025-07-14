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

### Inverse Velocity Kinematics Equations For Tread Drivetrain

<table>
  <tr>
    <th>Parameter</th>
    <th>Symbol</th>
    <th>Units</th>
  </tr>
  <tr>
    <td>Desired forward speed</td>
    <td>$V$</td>
    <td>$m/s$</td>

  </tr>
  <tr>
    <td>Desired yaw rate</td>
    <td>$\omega$</td>
    <td>$rad/s$</td>
  </tr>
  <tr>
     <td>Half the distance between the two treads</td>
    <td>$b/2$</td>
    <td>$m$</td>
    
  </tr>
  <tr>
    <td>Left-tread linear speed</td>
    <td>$v_l$</td>
    <td>$m/s$</td>
  </tr>
  <tr>
    <td>Right-tread linear speed</td>
    <td>$v_r$</td>
    <td>$m/s$</td>
  </tr>
  <tr>
    <td>Tread wheel radius</td>
    <td>$R$</td>
    <td>$m$</td>
  </tr>
  <tr>
    <td>Left wheel angular speed</td>
    <td>$\omega_l$</td>
    <td>$rad/s$</td>

  </tr>
  <tr>
    <td>Right wheel angualr speed</td>
    <td>$\omega_r$</td>
    <td>$rad/s$</td>

  </tr>
</table>

<b>Find the linear velocity of the two motors give the $V$ and $\omega$</b><br>
$v_l = V - (b/2)* \omega$<br>
$v_r = V + (b/2)* \omega$<br>

<b>Find the angular velocity of the two motors give the $V$ and $\omega$</b><br>
$w_l = \dfrac{V - (b/2)* \omega}{R}$<br>
$w_r = \dfrac{V + (b/2)* \omega}{R}$<br>



# Reference 
1. https://www.roboticsbook.org/S51_diffdrive_state.html