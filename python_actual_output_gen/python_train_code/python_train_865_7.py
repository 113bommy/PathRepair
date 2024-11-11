t1 = input()
t2 = input()
global d
d = {"monday":1,"tuesday":2,"wednesday":3,"thursday":4,"friday":5,"saturday":6,"sunday":7}
def abs(t1,t2):
	if d[t2] - d[t1] >= 0:
		return d[t2] - d[t1]
	else:
		return 6 + d[t2] - d[t1]
if abs(t1,t2) == 3 or abs(t1,t2) == 2 or abs(t1,t2) == 0:
	print("YES")	
else:
	print("NO")