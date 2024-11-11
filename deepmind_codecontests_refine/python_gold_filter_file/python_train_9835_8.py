n,x = map(int,input().split())
s = 0
t = 0
for i in range(n):
	l,r = map(int,input().split())
	s = s + (l-1-t)%x + r-l+1
	t = r

print(s)