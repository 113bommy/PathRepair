from bisect import *
from math import *
n = int(input())
arr = []
for i in range(n):
	x, y = input().split()
	x = int(x)-1
	y = int(y)-1
	arr.append((x, y))
if n%2==1:
	print("NO")
else:
	flag = True
	for i in range(0, n//2):
		if (arr[(i+1)%n][0]-arr[i%n][0], arr[(i+1)%n][1]-arr[i%n][1]) != (arr[(i+n//2)%n][0]-arr[(i+1+n//2)%n][0], arr[(i+n//2)%n][1]-arr[(i+1+n//2)%n][1]):
			flag = False
			break
	if flag == True:
		print("YES")
	else:
		print("NO")

