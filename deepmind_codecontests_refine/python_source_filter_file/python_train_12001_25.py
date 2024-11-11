import math
def solve(n,k,res):
    ans = 0
    res.sort()
    for i in range(1,n):
        if res[i] >= k:
            continue
        else:
            ans = ans + (k-res[i])/res[0]
    return ans

t = int(input())
while t:
    res = []
    n,k = map(int,input().split(" "))
    in_ = map(int,input().split(" "))
    for x in in_:
        res.append(int(x))
    print(solve(n,k,res))
    t-=1 
    