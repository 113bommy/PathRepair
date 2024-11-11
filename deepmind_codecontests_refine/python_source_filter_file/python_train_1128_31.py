n=int(input())
a=list(map(int,input().split()))
for i in range(n):
	a[i]//=400
free=0
b=set()
for i in range(n):
	if a[i]>=8:
		free+=1
	else:
		b.add(a[i])
cnt=len(b)
x=max(cnt,1)
y=min(cnt+free,9)
print(x,y)