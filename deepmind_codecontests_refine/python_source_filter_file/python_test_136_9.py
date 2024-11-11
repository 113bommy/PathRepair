import sys
import io, os
input = sys.stdin.buffer.readline
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

import itertools

t = int(input())
for _ in range(t):
    n = int(input())
    B = list(map(int, input().split()))
    m = n*(n+1)//2
    x = sum(B)
    if x%m != 0:
        print('NO')
        continue
    s = x//m
    A = []
    flag = True
    for i in range(n-1):
        y = B[(i-1)%n]-B[i%n]+s
        if y%n != 0:
            flag = False
            break
        a = y//n
        if a == 0:
            flag = False
            break
        A.append(a)
    if not flag:
        print('NO')
        continue
    a = s-sum(A)
    if a <= 0:
        print('NO')
        continue
    A.append(a)
    z = B[n-1]
    for i in range(n-1):
        z -= (n-i)*A[i]
    if z != A[n-1]:
        flag = False
    if sum(A) != s:
        flag = False
    if flag:
        print('YES')
        print(*A)
    else:
        print('NO')
