from bisect import bisect_right as br
from bisect import bisect_left as bl
MAX = 10**9
def isprime(n):
    n = abs(int(n))
    if n < 2:
        return False
    if n == 2: 
        return True    
    if not n & 1: 
        return False
    for x in range(3, int(n**0.5) + 1, 2):
        if n % x == 0:
            return False

    return True

def mhd(a,b,x,y):

    return abs(a-x)+abs(b-y)


n,m = map(int,input().split())
v = []
h = []
for _ in range(n):
    v.append(int(input()))

for _ in range(m):
    x1,x2,y = map(int,input().split())
    if(x1==1):
        h.append(x2)
lh = len(h)
h.sort()
if not lh:
    print(0)
elif n==0:
    print(lh-bl(h,MAX))
else:
    mn = n+lh-bl(h,MAX)
    for i in range(n):
        mn = min(mn,lh-bl(h,v[i])+i)
    print(mn)
