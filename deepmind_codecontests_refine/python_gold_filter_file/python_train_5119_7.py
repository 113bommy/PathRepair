def add(n):
	global a
	a.append(n)
	a.sort()

n, m = map(int, input().split())
s = list(map(int, input().split()))
ssum = s[0]
a = list()
ans = [0] * n
add(s[0])

for i in range(1, n):
	if ssum + s[i] > m:
		j = len(a) - 1
		temp = ssum
		while temp + s[i] > m:
			ans[i] += 1
			temp -= a[j]
			j -= 1

	ssum += s[i]
	add(s[i])

print(*ans)