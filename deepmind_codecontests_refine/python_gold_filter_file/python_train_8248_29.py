def solve():
	n = int(input())
	l = list(map(int,input().split()))
	Max = max(l)
	temp = set(l)
	for x in range(1,1025):
		temp1 = set(map(lambda y:y^x ,l))
		if temp==temp1:
			return x
	return -1

t = int(input())
for i in range(t):
	ans = solve()
	print(ans)
