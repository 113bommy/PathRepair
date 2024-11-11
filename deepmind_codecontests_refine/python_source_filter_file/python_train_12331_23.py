from math import ceil
a = list(map(int, input().split()))
b = list(map(int, input().split()))
n = int(input())

if ceil((sum(a) / 5) + (sum(b) / 10)) > n:
    print('NO')
else:
    print('YES')
