t = int(input())
a = []
for _ in range(t):
	n = int(input())
	s = list(map(int,input().split()))
	s.sort()
	minus = s[0]
	ans = -10000000000000000000000000000000000000000000
	for i in range(n):
		ans = max(ans, s[i]-minus)
		minus = s[i]
	a.append(ans)
for elem in a:
	print(elem)
