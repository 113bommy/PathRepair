n,m = [int(i) for i in input().split()]
l = n*['']
for i in range(n):
	l[i] = input()
s = ''
for i in range(m):
	f = l[0][i]
	for j in range(n):
		f = max(l[j][i])
	s+=f
ans = 0
for i in range(n):
	t = 0
	for j in range(m):
		if l[i][j] == s[j]:
			t=1
			break
	ans+=t
print(ans)
