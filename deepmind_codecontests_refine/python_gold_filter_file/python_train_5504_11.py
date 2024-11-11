import sys
f = sys.stdin
n = int(f.readline())
for _ in range(n):
    a = f.readline().strip()
    b = f.readline().strip()
    c = int(a) + int(b)
    c = '{}'.format(c)
    print(c if len(c) <= 80 else 'overflow')