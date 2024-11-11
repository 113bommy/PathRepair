import sys
f = sys.stdin.readline
n, a, b = map(int, f().strip().split())
x = [int(v) for v in f().strip().split()]
out = []
for v in x:
    p = (v*a)//b
    out.append(v - (p*b)//a - int(p*b%a!=0))
print(' '.join(map(str, out)))