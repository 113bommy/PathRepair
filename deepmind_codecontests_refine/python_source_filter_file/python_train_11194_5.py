n,a,b = map(int,input().split())
cnt = 0
d = []

for i in range(a):
	if a*b==a**2 and i%2!=0:
		s = [i for i in range(cnt+1,cnt+b+1)][::-1]
		cnt = s[0]
	else:
		s = [i for i in range(cnt+1,cnt+b+1)]
		cnt = s[-1]
	d.append(s)

for i in d:
	for j in range(b):
		if i[j]>n:
			i[j]=0
if n>a*b:
	print(-1)
else:
	for i in d:
		print(*i)

