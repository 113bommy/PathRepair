n=int(input())
l1,r1,l2,r2=[],[],[],[]
for i in range(n):
	l,r=map(int,input().split())
	l1.append(l)
	r1.append(r)
m=int(input())
for j in range(m):
	l,r=map(int,input().split())
	l2.append(l)
	r2.append(r)
a=max(-min(r1)+max(l2), -min(r2)+max(l1))

if a>0:
	print(a)
else:
	print(0)
