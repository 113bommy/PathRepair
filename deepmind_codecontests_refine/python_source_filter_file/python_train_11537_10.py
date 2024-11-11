from bisect import bisect
A,B,Q=map(int, input().split())
s=[int(input()) for _ in range(A)] + [10**10]
t=[int(input()) for _ in range(B)] + [10**10]
for _ in range(Q):
	x = int(input())
	ans = []
	ps = bisect(s, x)
	pt = bisect(t, x)
	for vs in (s[ps], s[ps-1]):
		for vt in (t[pt], t[pt-1]):
			ans.append(abs(x - vs) + abs(vs - vt))
			ans.append(abs(x - vt) + abs(vt - vs))
	print(min(ans))
