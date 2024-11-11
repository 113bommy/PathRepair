currentFloor,desiredFloor,liftFloor,timeStairs,timeLift,timeDoorOC = map(int,input().split())
liftTimeToCurrent = 0
# Stairs
stairTime = abs(currentFloor-desiredFloor)*timeStairs
#Lift
if currentFloor != liftFloor:
    liftTimeToCurrent = abs(liftFloor-currentFloor)*timeLift
    
liftTime = (2*timeDoorOC) + liftTimeToCurrent + abs(currentFloor-desiredFloor)*timeLift + timeDoorOC
if stairTime > liftTime:
    print("YES")
else:
    print("NO")