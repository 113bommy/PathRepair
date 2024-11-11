import math
t=int(input())
for _ in range(t):
    li=[int(k) for k in input().split()]
    li.sort()
    a=abs(li[1]-li[0])
    ans=math.ceil((li[2]-a)/2)
    x=li[1]+ans
    y=li[0]+(li[1]-ans)
    if(x==y):
        print(x)
    else:
        print(min(x,y))
