p=[];a=[]
m,n=map(int,input().split())
for i in range(n):
	x=int(input())%m
	if x in p:
		a.append(i+1)
	p.append(x)
print(a[0] if len(a)!=0 else '-1')