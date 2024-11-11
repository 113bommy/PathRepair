import sys
f = sys.stdin.readline
n, a, b = map(int, f().strip().split())
x = [int(v) for v in f().strip().split()]
out = []
for v in x:
    out.append(v%b)
print(' '.join(map(str, out)))