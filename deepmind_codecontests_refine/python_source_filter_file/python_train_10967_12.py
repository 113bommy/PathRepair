a, b = map(int,input().split())
ans = 0
l = list(map(int,input().split()))
for i in range(b):
	for i in range(1 ,len(l ) - 1):
		if ans == b:
			print(*l)
			exit()
		if l[i] > l[i + 1] and l[i] > l[i - 1] :
			if l[i] - 1 < l[i -1 ] or l[i] -1 < l[i + 1]:
				pass
			else:
				l[i] -= 1
				ans += 1
print(*l)
