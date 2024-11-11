import sys
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))

def borderinside_1(x,y,n,d): #0,0 and x,y on opposite sides
	a = -d
	b = x+y -d

	if ((a >= 0) ^ (b < 0)) == 0: #same sign = 1 oppositwe sign = 0
		return 1
	else:
		return 0

def borderinside_2(x,y,n,d): # same sides
		a = -2*n + d
		b = x+y -2*n +d
		if b == 0 :
		    b = -1
		if ((a >= 0) ^ (b < 0)) == 0:
			return 0
		else:
			return 1


def borderinside_3(x,y,n,d): # same sides
	a = d
	b = y-x +d
	if ((a >= 0) ^ (b < 0)) == 0:
		return 0
	else:
		return 1

def borderinside_4(x,y,n,d): # same sides
	a =  +d
	b = x-y +d
	if ((a >= 0) ^ (b < 0)) == 0:
		return 0
	else:
		return 1

def check_inside(n,d,gr_x,gr_y):
	check_side1 = borderinside_1(gr_x,gr_y,n,d)
	check_side2 = borderinside_2(gr_x,gr_y,n,d)
	check_side3 = borderinside_3(gr_x,gr_y,n,d)
	check_side4 = borderinside_4(gr_x,gr_y,n,d)
	#print(check_side1, check_side2,check_side3,check_side4)
	if (check_side4 & check_side3 & check_side2 & (check_side1))==1:
		print("YES")
	else:
		print("NO")
	return 0
	
borders = inlt()
if borders[0] > borders[1]:
	n = borders[0]
	d = borders[1]
else:
	d = borders[0]
	n = borders[1]
#print(n,d)

num_points = inp()

for x in range(0,num_points):
	grasshopper = inlt()
	grasshopper_x = int(grasshopper[0])
	grasshopper_y = int(grasshopper[1])
#	if grasshopper_x==0 & grasshopper_y==0:
#		print("NO")
#	else:
	check_inside(n,d,grasshopper_x,grasshopper_y)