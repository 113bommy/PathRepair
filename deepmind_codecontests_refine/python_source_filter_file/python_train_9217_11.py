import sys
import math

inf = 100000000

n = int(input())
a = [int(e) for e in input().split()]
f = [[0, 0, 0] for i in range(n)]
m = inf
f[0][0] = 1
if a[0] == 1 or a[0] == 3:
	f[0][1] = 0
else:
	f[0][1] = inf
if a[0] == 2 or a[0] == 3:
	f[0][2] = 0
else:
	f[0][2] = inf
if a[0] == 3:
	f[0][1] = f[0][2] = inf
m = min(f[0])
for i in range(1, n):
	f[i][0] = min(f[i - 1]) + 1	
	if a[i] == 1 or a[i] == 3:
		f[i][1] = min(f[i-1][0], f[i-1][2])
	else:
		f[i][1] = inf
	if a[i] == 2 or a[i] == 3:
		f[i][2] = min(f[i-1][0], f[i-1][1])
	else:
		f[i][2] = inf
	if a[i] == 0:
		f[i][1] = f[i][2] = inf
	m = min(f[i])
print(m)
