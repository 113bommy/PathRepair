n,m=map(int,input().split())
p1=(m-1)//2
p2=m//2
if n%2:
	p1=m//2
order=[p1]
if p1!=p2:
	order.append(p2)
while(p1>0 and p2<m-1):
	p1-=1
	p2+=1
	order.append(p1)
	order.append(p2)
while(p1>0):
	p1-=1
	order.append(p1)
while(p2<m-1):
	p2+=1
	order.append(p2)
for i in range(n):
	print(order[i%m]+1)
