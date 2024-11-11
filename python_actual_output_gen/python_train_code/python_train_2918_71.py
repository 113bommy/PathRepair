a,b=map(int,input().split())
c,d=0,0
if a>b:
    c=b 
    a=a-b
    if a>2:
        d=a//2 
else:
    c=a
    b=b-a
    if b>2:
        d=b//2 
print(c,d)