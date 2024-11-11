def solve():
	modx = 179426080107
	n,m = map(int,input().split())
	cnt = 0
	a = []
	for i in range(n + 1):
		s = input()
		if(s == '?'): cnt += 1
		a.append(s)

	#print(cnt)

	if (m == 0):
		if (a[0] == '0') : return 1
		if (a[0] == '?' and (n + 1 - cnt)% 2 == 1):
			return 1
		return 0

	if(cnt):
		if (n % 2 == 1):return 1
		return 0

	for i in range(n+1):
		a[i] = int(a[i])

	now = a[n]

	tmp = 1
	ans = 0
	for i in range(n + 1):
		ans = ans + (tmp * a[i]) % modx
		ans %= modx
		tmp = (tmp * m) % modx

	if (ans == 0) : return 1
	else : return 0

if (solve() == 1) : print("Yes")
else : print("No")



