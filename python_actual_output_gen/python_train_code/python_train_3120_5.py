x,y = map(int,input().split())
s = list(map(int,input().split()))
t = 0
t1 = 0
for i in range(x):
	if s[i]<=0:
		t = t + s[i]
	else:
		t1 = t1 + s[i]
r = -t
if r<t1:
	if (t1-t)%y != 0:
		print(int((t1+t)/y)+1)
	else:
		print(int((t1+t)/y))
else:
	if (r-t1)%y != 0:
		print(int((r-t1)/y)+1)
	else:
		print(int(r-t1/y))