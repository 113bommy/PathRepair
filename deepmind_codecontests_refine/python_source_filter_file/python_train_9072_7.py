import math
n = int(input())
m = math.ceil(n/2 + 1)
i, j, k = 0, 1, 2
print(m)
while (i < n):
    print(1,j)
    i += 1
    j += 1
    if (j == m+1):
        while (i < n):
            print(k,m)
            k += 1
            i += 1

    
