from math import gcd

mod = 10**9 +7
N = int(input())
dic = {}

zero = 0
for _ in range(N):
    a,b = map(int, input().split())
    if  a ==0 and b == 0:
        zero += 1
        continue
    elif a == 0:
        key = (0,1)
    elif b == 0:
        key = (1,0)
    else:
        if a<0:
            a=-a 
            b=-b
        g = gcd(a,abs(b))
        key = (a//g,b//g)
    
    if key not in dic:
        dic[key]=0

    dic[key] +=1

ans = 1
for k1, v1 in dic.items():
    if v1 ==0:
        continue

    if k1[1] >0:
        k2 = (k1[1],-k1[0])
    else:
        k2 = (-k1[1],k1[0])

    if k2 not in dic:
        ans *= 2**v1
        ans %= mod
    else:
        ans *= ((2**v1-1)) %mod) + ((2**dic[k2]-1)) %mod) +1
        ans %= mod
        dic[k2]=0

ans = (ans + zero -1 )%mod
print(ans)