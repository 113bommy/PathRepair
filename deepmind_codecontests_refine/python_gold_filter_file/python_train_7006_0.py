n, m = map(int, input().split())
s = str(input())
t = str(input())

pref = [-1] * m
idx = 0
for i in range(n):
	if t[idx] == s[i]:
		pref[idx] = i
		idx += 1
		if idx == m:
			break

suff = [-1] * m
idx = m-1
for i in range(n-1, -1, -1):
	if t[idx] == s[i]:
		suff[idx] = i
		idx -= 1
		if idx < 0:
			break

ans = 0
for i in range(0, m-1):
	ans=max(ans, suff[i+1] - pref[i])
print(ans)