import math as m

def findr(num):
    while num%2==0:
        num /= 2
    return num

t = int(input())
for _ in range(t):
    a,b = list(map(int,input().split()))
    a,b = max(a,b),min(a,b)
    ar = findr(b)
    if findr(a) != ar:
        print(-1)
    else:
        ans = 0
        a /= b
        while a>=8:
            a/= 8
            ans += 1
        if a>1:
            ans += 1
        print(ans) 