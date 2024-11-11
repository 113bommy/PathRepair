# Python3 implementation of the approach 
import sys
import math
from functools import reduce
from math import sqrt 

def float_gcd(a, b, rtol = 1e-05, atol = 1e-08):
    t = min(abs(a), abs(b))
    while abs(b) > rtol * t + atol:
        a, b = b, a % b
    return a

def side_length(p1, p2):
	return (math.hypot(p2[0] - p1[0], p2[1] - p1[1]))

def get_num_sides(p1, p2, p3):
	sides = {}
	sides[side_length(p1, p2)] = [p1, p2]
	sides[side_length(p2, p3)] = [p2, p3]
	sides[side_length(p3, p1)] = [p3, p1]
	s = list(sorted(sides.keys()))
	#print (s)
	cAng = [math.acos(1- (ms*ms / (2 * radius * radius))) for ms in s]
	cAngDegF = [round(x * 360/(2*math.pi),3) for x in cAng]
	for c in range(3,100):
		cAF = 360/c
		#print(cAF, cAngDegF, [abs((x / cAF) - round(x/cAF)) for x in cAngDegF])
		err = sum([abs((x / cAF) - round(x/cAF)) for x in cAngDegF])
		#print ('sides {} =, err = {:6f}'.format(c, err), file=sys.stderr)
		if (err < 0.001): break
	return (c)

	cAngGCDF = 360 // side_count
	print ('regular angle={}, sides={}'.format(cAngGCDF, side_count), file=sys.stderr)
	return(side_count)

def define_circle(p1, p2, p3):
    """
    Returns the center and radius of the circle passing the given 3 points.
    In case the 3 points form a line, returns (None, infinity).
    """
    temp = p2[0] * p2[0] + p2[1] * p2[1]
    bc = (p1[0] * p1[0] + p1[1] * p1[1] - temp) / 2
    cd = (temp - p3[0] * p3[0] - p3[1] * p3[1]) / 2
    det = (p1[0] - p2[0]) * (p2[1] - p3[1]) - (p2[0] - p3[0]) * (p1[1] - p2[1])

    if abs(det) < 1.0e-6:
        return (None, math.inf)

    # Center of circle
    cx = (bc*(p2[1] - p3[1]) - cd*(p1[1] - p2[1])) / det
    cy = ((p1[0] - p2[0]) * cd - (p2[0] - p3[0]) * bc) / det

    radius = math.sqrt((cx - p1[0])**2 + (cy - p1[1])**2)
    return ((cx, cy), radius)

pts = []
for _ in range(3):
	(x,y) = list(map(float,input().split()))
	pts = pts + [[x, y]]
#print (pts)

center, radius = define_circle(pts[0], pts[1], pts[2])
#print (center, radius)
sidecount = get_num_sides (pts[0], pts[1], pts[2])
#sidecount = 13
cAng = 2 * math.pi / sidecount
area = 0.5*radius*radius*math.sin(math.pi-cAng)*sidecount
print ('{:.6f}'.format(area))

if False:
	if center is not None:
		plt.figure(figsize=(4, 4))
		circle = plt.Circle(center, radius)
		plt.gcf().gca().add_artist(circle)
		plt.show()
