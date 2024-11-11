from math import factorial

nm = input().split()
n = int(nm[0])
m = int(nm[1])

f = []

i = 2
j = 0
while (m > 1) and i<=m:
    while m%i == 0:
        m /= i
        j += 1
    if j >= 1:
        f.append(j)
    i += 1
    j = 0

        
ans = 1

for k in f:
    if k > 0:
        ans *= factorial(n+k-1) // (factorial(k) * factorial(n-1))
    
print(int(ans) % (10**9+7))
