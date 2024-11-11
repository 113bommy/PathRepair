import math

succ = [float(i) for i in input().split()]
err = [float(i) for i in input().split()]
hack = [float(i) for i in input().split()]
val = [float(500),float(1000),float(1500),float(2000),float(2500)]

points = 0

for i in range(5):
    points = points + max(0.3*val[i], (1-succ[i]/250)*val[i] - 50*err[i])

points = points + hack[0]*100 - hack[1]*50

print(math.ceil(points))
