n,x = map(int,input().split())
t = 0
s = 0
for i in range(n):
	l,r = map(int,input().split())
	s = s + (l-t)%x + r-l
	t = r
print(s)
