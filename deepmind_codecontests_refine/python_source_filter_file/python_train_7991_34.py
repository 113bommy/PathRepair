import math

N,K = map(int,input().split())
A = list(map(int,input().split()))

m = 0
M = max(A)

while(M-m>0.01):
    mm = 0

    mid = (M+m)/2
    for i in range(N):
        mm += math.ceil(A[i]/mid)-1

    if mm>K:
        m = mid
    else:
        M = mid

print(math.ceil(mid))


