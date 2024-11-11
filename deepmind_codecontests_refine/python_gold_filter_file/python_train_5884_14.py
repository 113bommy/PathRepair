a,b=map(int,input().split())
x,y=0,0
res=0
for i in range(60):
    if a>=2**i and a<2**(i+1) :
        x=i+1
        break
for i in range(60):
    if b>=2**i and b<2**(i+1) :
        y=i+1
        break
for i in range(x,y+1):
    t=2**(i)-1
    for j in range(i-1):
        d=t-2**j
        if d>=a and d<=b :
            res+=1
print(res)
