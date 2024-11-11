from math import ceil as c
t,s,x = map(int,input().split())
h,k = (x-t)/s,((x-t)/s)-1
if k>=0 and int(k)==c(k) or h>=0 and int(h)==c(h):
	print("YES")
else:
	print("NO")