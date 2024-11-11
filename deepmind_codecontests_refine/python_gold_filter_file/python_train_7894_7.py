import math
D,M=list(map(int,input().split()))
if abs(D-M)>1:
    print(0)
    exit()
if D==M:
    print((2*(math.factorial(D)**2))%1000000007)
else:
    print((math.factorial(D)*math.factorial(M))%1000000007)