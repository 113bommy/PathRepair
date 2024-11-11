from math import sqrt, ceil
n, m = [int(x) for x in input().split()]

count = 0
for b in range(n):
    a = sqrt(n - b)
    if (a + b**2) == m:
        count+=1

print(count)      
