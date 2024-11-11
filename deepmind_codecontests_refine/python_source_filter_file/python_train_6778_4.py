# -*- coding: utf-8 -*-

n, m = map(int, input().split())

cnt = 0
if n <= m:
    for i in range(1, n+1):
        for j in range(1, n+1):
            if (pow(i, 2) + pow(j, 2)) % m == 0:
                cnt += 1
else:
    for i in range(1, m+1):
        for j in range(1, m+1):
            if (pow(i, 2) + pow(j, 2)) % m == 0:
                cnt += 1
    cnt *= pow(n // m, 2)
    a = 0
    for i in range(1, m+1):
        for j in range(1, n%m+1):
            if (pow(i, 2) + pow(j, 2)) % m == 0:
                a += 1
    cnt += a * n // m
    b = 0
    for i in range(1, n%m+1):
        for j in range(1, m+1):
            if (pow(i, 2) + pow(j, 2)) % m == 0:
                cnt += 1
    cnt += b * n // m
    for i in range(1, n%m+1):
        for j in range(1, n%m+1):
            if (pow(i, 2) + pow(j, 2)) % m == 0:
                cnt += 1
print(cnt)
