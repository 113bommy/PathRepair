n=int(input())
b=100
m=0
for i in range(n):
	a,p=map(int,input().split())
	if i>0:
		b=min(b,p)
	if i==0:
		m+=a*p
	else:
		m+=a*b
print(m)