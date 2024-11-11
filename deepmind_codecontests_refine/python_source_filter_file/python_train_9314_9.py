n,x,y=map(int,input().split())
s=set()
f=0
for i in range(n):
    x1,y1=map(int,input().split())
    if x1!=x:
        m=(y1-y)/(x1-x)
        s.add(abs(m))
    else:
        f=1
if f==0:
    print(len(s))
else:
    print(len(s)+1)