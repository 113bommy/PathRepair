# t1: h          = (h+c)/2 + (h-c)/2
# t2: (h+c)/2
# t3: (2h+c)/3   = (h+c)/2 + (h-c)/6
# t4: (h+c)/2
# t5: (3h+2c)/5  = (h+c)/2 + (h-c)/10
# t6: (h+c)/2

# output 1: (h+c)/2 + (h-c)(1/(1x3)) <= t < h
# output 3: (h+c)/2 + (h-c)(2/(3x5)) <= t < ...
# output 5: (h+c)/2 + (h-c)(3/(5x7)) <= t < ...
# output 7: (h+c)/2 + (h-c)(4/(7x9)) <= t < ...

# 1x3/1 = (2^2-1)/1 = 4x1 - 1/1
# 3x5/2 = (4^2-1)/2 = 4x2 - 1/2
# 5x7/3 = (6^2-1)/3 = 4x3 - 1/3
# 7x9/4 = (8^2-1)/4 = 4x4 - 1/4

import math

T = int(input())
for _ in range(T):
	h,c,t = map(int,input().split())
	if 2*t <= h+c:
		print(2)
	else:
		estimate = (h-c)//(2*t-(h+c))//2
		if (h+c)*(4*(estimate+1)**2-1) + 2*(h-c)*(estimate+1) <= 2*t*(4*(estimate+1)**2-1):
			print(2*estimate+1)
		else:
			print(2*estimate-1)