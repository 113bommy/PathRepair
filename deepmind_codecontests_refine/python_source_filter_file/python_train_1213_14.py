import math
n,a,b=map(int,input().split())#5 10 10
c=list(map(int,input().split()))#1000 1 1 1
val=math.floor(((c[0]*a)/b)-c[0])#4
moves=0
if c[0]*a/sum(c)>=b:
    print(0)
else:
    c.pop(0)
    c.sort()
    s=sum(c)
    while s>val and len(c)!=0:
        s-=c.pop()
        moves+=1
    print("mov",moves)

