i=int(input())
m=0
n=0
c=0
d=0
for x in range(i):
	l=list(map(int,input().split()))
	if l[0]==1:
		m+=l[1]
		n+=l[2]
	else:
		c+=l[1]
		d+=l[2]
if m>=n:print("ALIVE")
else:print("DEAD")
if c>=d:print("ALIVE")
else:print("DEAD")