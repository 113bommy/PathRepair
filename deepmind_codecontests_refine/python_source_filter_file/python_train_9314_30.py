import sys
import math

a = [int(i) for i in input().split(' ')]
n = a[0]
gun = (a[1],a[2])
stormtroopers = []
for i in range(n):
    trooper = [int(i) for i in input().split(' ')]
    stormtroopers.append((trooper[0],trooper[1]))
    
angles = []
for i in stormtroopers:
    xDist = i[0] - gun[0]
    yDist =  i[1] - gun[1]
    dist = math.sqrt(math.pow(xDist, 2) + math.pow(yDist, 2))
    theta = math.atan2(yDist, xDist)
    theta = theta if theta > 0 else theta + math.pi
    #theta = theta if theta != math.pi else 0
    theta = round(theta, 7)
    if theta not in angles:
    	angles.append(theta)
print(len(angles)) 