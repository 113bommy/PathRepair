#!/usr/bin/env python
x,y = map(int,input().split())
if x % y  == 0 or x > 10**18:
	print(-1)
else:
	print(x)
	 
