n,m = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
ans = 1
m = a[-1]
mod = 998244353
ml = [0]*n
for i in range(n-1,-1,-1):
	m = min(m,a[i])
	ml[i] = m
r = n
l = 0
for temp in b[::-1]:
	while r-1>=0 and ml[r-1]>temp:
		r-=1
	if r == 0 or ml[r-1]!=temp:
		ans = 0
		break
	l = r-1
	while l-1>=0 and ml[l-1] == temp:
		l-=1
	if l:
		ans = ans*(r-l)%mod
	r = l
if l:
	ans = 0
else:
	print(ans)

