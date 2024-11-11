import math

n = int(input())

A = [int(x) for x in input().split()]

B = [int(x) for x in input().split()]

D = {0:0}
free = 0

for i in range(n):
    if A[i] == 0:
        if B[i] == 0:
            free += 1
    elif B[i] == 0:
        D[0] += 1
    else:
        t = math.gcd(A[i],B[i])
        a = A[i]//t
        b = B[i]//t
        if a < 0 and b < 0: 
            if (-a,-b) in D:
                D[(-a,-b)] += 1
            else:
                D[(-a,-b)] = 1
        elif a > 0 and b <0:
            if (a,b) in D:
                D[(a,b)] += 1
            else:
                D[(a,b)] = 1
        elif a < 0 and b > 0:
            if (-a,-b) in D:
                D[(-a,-b)] += 1
            else:
                D[(-a,-b)] = 1
        else:
            if (a,b) in D:
                D[(a,b)] += 1
            else:
                D[(a,b)] = 1
            
            
print(max(D.values()))
