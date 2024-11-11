import sys

n, a, b = map(int, input().split())
c = [int(x) for x in input().split()]
s = 0
for i in range(n//2):
    if c[i] == 2 and c[n - i - 1] == 2:
        s += min(a,b)
    elif c[i] != 2 and c[n - i - 1] != 2:
        if c[i] != c[n - i - 1]:
            print(-1)
            sys.exit()
    elif c[i] == 2:
        if c[n - i - 1] == 0:
            s += a
        else:
            s += b
    else:
        if c[i] == 0:
            s += a
        else:
            s += b
if n % 2 != 0:
    if c[n//2] == 2:
        s += min(a,b)
print(s)
