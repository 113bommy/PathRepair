n,m = map(int,input().split())
AB = [(int(i) for i in input().split()) for j in range(n)]
AB.sort()
res = 0
for a,b in AB:
	m -= b
	if m >= 0:
		res += a*b
	else:
		m += b
		res += a*m
		break
print(res)
