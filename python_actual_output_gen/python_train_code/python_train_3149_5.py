n = int(input())
a = list(map(int, input().split()))
for i in range(n):
	if a[i]>=0:
		a[i] = 0 - a[i] -1
if n%2!=0:
	a[a.index(min(a))] = 0 - a[i] -1
print(*a)