import math

def optimize (start,end,d,n):
    if start > end :
        return 0
    else:
        mid = (end + start) // 2
        ans = math.ceil(d/(mid+1))
        if ans + mid <= n :
            return 1
        elif ans + mid > n :
            return optimize(mid+1,end,d,n)
        


def deadline (n,d):
    if d <= n :
        return "YES"
    else:
        if optimize (0,d,d,n) == 0 :
            return "NO"
        else:
            return "YES"


t = int(input())
for x in range(t):
    n,d = list(map(int,input().split()))
    print (deadline(n,d))
