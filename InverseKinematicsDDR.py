r = 1
L = 5
#
def inverseKinematicsDDR(V_x: float, W: float):
    left = (V_x/1) - ((L/2)*(W/r))
    right = (V_x/1) + ((L/2)*(W/r))
    return( left, right)

leftW, rightW = inverseKinematicsDDR(1,.3)
print("left wheel")
print(leftW)
print("right wheel")
print(rightW)