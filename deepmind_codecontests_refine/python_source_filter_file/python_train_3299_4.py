import math
n = int(input())
a = list(map(int, input().split()))
s = [0]*n
for i in range (n):
	if a[i] > i:
		s[i] = math.ceil((a[i] - i) / n)
	if a[i] <= i:
		print(i + 1)
		quit()
m = min(s)
for i in range (n):
	if s[i] == m:
		print(i + 1)
		quit
