t = int(input())
import collections
for _ in range(t):
    n0,n1,n2 = list(map(int,input().split()))
    res = []
    if not n1:
        if n0:
            res = "".join(["0" for _ in range(n0+1)])
        else:
            res = "".join(["1" for _ in range(n0+1)])
    else:
        for i in range(n1+1):
            if i&1 : res.append("0")
            else: res.append("1")
        for i in range(n0):
            res.insert(1,"0")
        for i in range(n2):
            res.insert(0,"1")
        res = "".join(res)
    print(res)