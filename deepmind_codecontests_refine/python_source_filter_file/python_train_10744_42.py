import math
q=int(input())
for _ in range(q):
    s=input().split()
    r=int(s[0])
    g=int(s[1])
    b=int(s[2])
    x=[]
    x.append(r)
    x.append(g)
    x.append(b)
    x.sort()
    
    if x[0]+x[1]>=x[2]:
        print("Yes")
    else:
        print("No")
    