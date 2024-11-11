error = 0.0001

from math import sqrt
for _ in range(int(input())):
    N = int(input())
    
    count = 0
    while N >= 3:
        count += 1

        n = sqrt(2*N/3 + 1/36) - 1/6
        if abs(n-round(n)) < error:
            n = round(n)
        n = int(n)
        N = int(N-(3*n*n + n)/2)
    
    print(count + (1 if N==2 else 0))