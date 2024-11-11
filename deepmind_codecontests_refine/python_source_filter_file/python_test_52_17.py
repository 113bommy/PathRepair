import math
t = int(input())
for i in range(t):
    n,k = input().split()
    n,k = int(n),int(k)
    s = 0
    while k!=0 :
        p = math.log(k)/math.log(2)
        p = int(p)
        s += n**p
        k-= 2**p
    print(int(s%(1e9+7)))