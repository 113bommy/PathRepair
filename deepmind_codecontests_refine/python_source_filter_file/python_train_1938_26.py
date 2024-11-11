import math
r,d = [int(x) for x in input().split()]
small_r = r-d
large_r = r
count = 0
for _ in range(int(input())):
	#count = 0
	x, y, ra = [int(x) for x in input().split()]
	dist1 = math.sqrt(x*x + y*y)
	inside1 = ((dist1- small_r) < 0)
	inside2 = ((dist1 - large_r) < 0)
	if(not inside1 and inside2):
		if(ra<=abs(dist1- small_r)):
			if(ra<= abs(dist1 - large_r)):
				count += 1
print(count)
		