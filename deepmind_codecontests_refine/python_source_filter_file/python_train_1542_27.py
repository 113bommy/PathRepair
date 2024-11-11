#!/usr/bin/env python3
n = int(input())
*a, = map(int, input().split())
b = [0]*(n//2) + a[n//2:]
for i in reversed(range(n//2)):
    b[i] = sum(b[(i+1)*(j+1)-1] for j in range(n//(i+1)))>>0 ^ a[i]
print(sum(b))
print(*[i+1 for i in range(n) if b[i]==1])
