#!/bin/python3
t = int(input())
while t > 0:
	mn = list(map(int, input().split()))
	if mn[0] % mn[1] == 0:
		print("YES")
	print("NO")
	
	t -= 1