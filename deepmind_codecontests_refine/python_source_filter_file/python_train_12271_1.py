import sys
input()
for e in sys.stdin:
    a, b, c = sorted(int(e.split()))
    if a**2 + b**2 == c**2:
        print('YES')
    else:
        print('NO')
