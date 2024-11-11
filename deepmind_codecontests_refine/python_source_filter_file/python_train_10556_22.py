a,b=list(map(int,input().split()))
if a*b>0:
    if a>0:
       c=[0,a+b,a+b,0]
    else:
       c=[a+b,0,0,a+b]
else:
    if a>0:
        c=[0,-a+b,a-b,0]
    else:
        c=[-a+b,0,0,a-b]
for i in c:
    print(i,end=' ')