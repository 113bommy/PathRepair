import math
 
n, k = map(int, input().split())
Ans = []

if n < (k+1)*k//2:
    print(-1)
else:
    d = n
    nd = 1
    for i in range(int(math.sqrt(n)), 1, -1):
        if n%i == 0:
            if i > nd and n//i >=(k+1)*k//2:
                nd = i
            elif n//i > nd and i >=(k+1)*k//2:
                nd = n//i

    d = n//nd
    for x in range(1, k):
        Ans.append(nd*x)
        d -= x
    Ans.append(d*nd)
        
     
    if len(Ans) !=  0:
        print(*Ans)
    else:
        print(-1)
