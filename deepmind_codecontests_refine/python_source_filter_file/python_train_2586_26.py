x=int(input())
a=[]
for i in range(x):
	a.append(int(input()))

ans=0
t=1
while t!=2 and ans<100000:
	ans=ans+1
	t=a[t-1]
if ans>50000:
	print(-1)
else:
	print(ans)