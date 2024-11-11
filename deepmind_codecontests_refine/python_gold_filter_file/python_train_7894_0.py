import sys
import math
n, m = (int(i) for i in input().split())
l=abs(n-m)
div=int(10**9+7)

if l>1:
    print(0)
    sys.exit()

if l==1:
    ans=(math.factorial(n)*math.factorial(m))%div
    print(ans)
else:
    ans=(math.factorial(n)*math.factorial(m)*2)%div
    print(ans)
