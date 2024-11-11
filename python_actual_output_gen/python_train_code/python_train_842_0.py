n = int(input())
a = list(map(int, input().split()))

m = max(a)
l = 0
ans = 0
for i in a:
	if a == m:
		l += 1
	else:
		l = 0
	ans = max(l, ans)
	
print(ans)