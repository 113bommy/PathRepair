n = int(input())
l1 = list(map(int,input().split()))
l2 = list(map(int,input().split()))
m1 = l1[1:]
m2 = l2[1:]
c,c1,f = 0,0,0
while len(m1)!=0 and len(m2)!=0:
	if m1[0]<m2[0]:
		c = m1.pop(0)
		m2.append(c)
		c = m2.pop(0)
		m2.append(c)
	else:
		c = m2.pop(0)
		m1.append(c)
		c = m1.pop(0)
		m1.append(c)
	c1+=1
	if  c1>2*n or m1==l1[1:] and m2==l2[1:]:f=1;break
if f==1: print(-1)
elif len(m1)==0:print(c1,2)
else:print(c1,1)