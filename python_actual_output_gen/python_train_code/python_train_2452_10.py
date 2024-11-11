n,*a=map(int,open(0).read().split())

b=[i for i in a if i>0]
c=a.count(0)
d=[i for i in a if i<0]

plus=sum(b)-len(b)
minus=-(sum(d)+len(d))
if len(d)%2:
    minus+=2
print(plus+c+minus)