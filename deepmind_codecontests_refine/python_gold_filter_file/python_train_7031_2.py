q=input()
p1,p2,p3,p4,a,b=map(int,q.split())
p=min(p1,p2,p3,p4)
c=0
if p>b:
    c=b-a+1
elif p>a:
    c=p-a
else:
    c=0
print(c)
