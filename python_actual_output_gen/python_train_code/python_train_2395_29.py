na,nb=map(int,input().split());k,m=map(int,input().split())
a=list(map(int,input().split()));b=list(map(int,input().split()));c=0
for i in range(na-1,-1,-1):
	if a[i]<b[0]:c=i+1;break
if c>=k:print('YES')
else:print('NO')