r = 4.7625
L = 13.97 
#
def inverseKinematicsDDR(V_x: float, W: float):
    left = (V_x/r) - ((L/2)*(W/r))
    right = (V_x/r) + ((L/2)*(W/r))
    return( left, right)

leftW, rightW = inverseKinematicsDDR(150,0)
print("left wheel")
print(leftW)
print("right wheel")
print(rightW)