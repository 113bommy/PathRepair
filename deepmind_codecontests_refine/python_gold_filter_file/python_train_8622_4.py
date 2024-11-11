#!/usr/bin/env python3
Q = int(input())
prime = [0] + [1] * 10**5
prime[1] = 0
c = [0]
for i in range(1, 10**5 + 1):
    if prime[i]:
        c.append(c[-1] + prime[(i + 1) // 2])
        if i <= 10**2.5:
            for j in range(2, 10**5 // i+1):
                prime[j * i] = 0
    else:
        c.append(c[-1])
for i in range(Q):
    l, r = map(int, input().split())
    print(c[r] - c[l-1])
