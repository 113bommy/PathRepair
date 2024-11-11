# coding: utf-8
# Your code here!
import sys
read = sys.stdin.read
readline = sys.stdin.readline

n,*a = map(int,read().split())

v = 0
for i in a[2:]:
    v ^= i

w = a[0]+a[1]

z = w-v
if z&1==1 or z<0:
    print(-1)
else:
    z //= 2
    """
    z = p&q
    v = p^q
    """
    if z&v:
        print(-1)
        exit()

    ans = z
    for i in range(60,-1,-1):
        m = 1<<i
        if v&m:
            if ans+m <= a[0]:
                ans += m
                #print(ans,i)

    if ans > a[0] or ans==0: print(-1)
    else: print(a[0]-ans)        
        
        
        
        
            




