import sys,functools,collections,bisect,math
input = sys.stdin.readline
#print = sys.stdout.write

n,k = map(int,input().strip().split())
arr = list(map(int,input().strip().split()))

l = 0
h = n+1
while l < h:
    mid = (l+h)//2
    res = [0]
    for i in arr:
        if i < mid:
            res.append(res[-1]-1)
        else:
            res.append(res[-1]+1)
    mi = 0
    for i in range(n-k+1):
        mi = min(mi,res[i])
        if res[i+k]-mi > 0:
            l = mid+1
            break
    else:
        h = mid

print(l-1)

