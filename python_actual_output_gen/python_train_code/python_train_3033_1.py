x = list(map(int, input().split()))
x.sort()
ans = 0
if x[1] == x[2]:
	if x[0] != x[1]:
		ans = x[1] - 1
	else:
		ans = 0
else:
	ans = x[2]-1-x[1] + x[2]-1-x[0]
print (ans)
