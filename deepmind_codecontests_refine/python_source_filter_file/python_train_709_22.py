n = int(input())
a = list(map(int, input().split()))

f = 0
d = 0
for x in a:
    if x % 4 == 0:
        f += 1
    elif x % 2 == 0:
        d += 1

if 0 < d < n:
    d -= 1

if n > f * 3 + d:
    print('No')
else:
    print('Yes')
