from itertools import*


n,*b=map(int,open(0).read().split())

a1=sum(b[i]*(-1)**(i%2) for i in range(n))


l=[a1]
for i in range(n-1):
    l.append((b[i]-l[-1]//2)*2)
print(l)