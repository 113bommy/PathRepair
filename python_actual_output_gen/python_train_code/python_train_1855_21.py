p=[];a=[]
m,n=map(int,input().split())
for i in range(n):
	x=int(input())
	if x in p:
		a.append(i)
	p.append(x)
print(a[0] if len(a)!=0 else '-1')