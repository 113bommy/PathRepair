
from math import ceil, sqrt


T = int(input())
for _ in range(T):
    N, K = map(int, input().split())

    if K >= N:
        print(1)
        continue
    last_factor = 1
    for i in range(2, min(K+1, ceil(sqrt(N))+1)):
        if N%i == 0:
            if N//i <= K:
                last_factor = N//i
                break
            else:
                last_factor = i
            
    print(N//last_factor)
    
