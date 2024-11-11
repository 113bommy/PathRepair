from itertools import permutations

def C(l):
	for i in range(15):
		if 7**i > l: return i
	return -1

n,m = map(int,input().split())
n -= 1
m -= 1
n1, n2 = (C(n), C(m))
if n1+n2 > 7:
	print(0)
	exit()
ans = 0
for i in list(permutations(list(range(0,7)), n1+n2)):
	ans1, ans2 = (0, 0)
	for j in range(n1):
		ans1 += (7**j)*i[j]
	for j in range(n1, n1+n2):
		ans2 += (7**(j-n1))*i[j]
	if ans1 <= n and ans2 <= m:
		ans += 1
print(ans)
