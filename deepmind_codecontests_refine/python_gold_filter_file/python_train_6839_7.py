import sys


n, k = map(int, sys.stdin.readline().split())
an = list(map(int, sys.stdin.readline().split()))
d = {}
for i in range(n):
    if an[i] not in d:
        d[an[i]] = i+1

if len(d) >= k:
    print('YES')
    count = 0
    for _, v in d.items():
        print(v, end = ' ')
        count += 1
        if count == k:
            break
    print()
else:
    print('NO')
