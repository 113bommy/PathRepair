import math
N,M = map(int,input().split())

if(abs(N-M)<=2):
    if(N==M):
        print((math.factorial(N)*math.factorial(M)*2)%(10**9+7))
    else:
        print(math.factorial(M)*math.factorial(N)%(10^9+7))
else:
    print(0)