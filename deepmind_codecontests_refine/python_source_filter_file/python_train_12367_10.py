import sys
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = sorted([[a[i], b[i]] for i in range(n)], key=lambda x: x[1])
a = [(x[0], i) for i, x in enumerate(c)]
b = [x[1] for x in c]
a.sort()
for i in range(n):
	if a[i][0] > b[i]:
		print("No")
		sys.exit()
cur, cnt = 0, 0
while a[cur][1] != 0:
	cnt += 1
	cur = a[cur][1]
if cnt < n-1:
	print("Yes")
else:
	for i in range(n-1):
		if a[i][0] <= b[i+1]:
			print("Yes")
			break
	else:
		print("No")