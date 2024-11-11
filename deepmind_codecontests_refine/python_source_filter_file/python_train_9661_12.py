import sys

readline = sys.stdin.readline

N = int(readline())
A = list(map(int, readline().split()))

A.sort()

amax = A.pop(-1)
amin = A.pop(0)
neg = [a for a in A if a < 0]
pos = [a for a in A if a >= 0]

log = []

m = amin
for a in pos:
    log.append((m, a))
    m = m - a

M = amax
for a in neg:
    log.append((m, a))
    M = M - a

log.append((M, m))
ans = M - m

print(ans)
for l, r in log:
    print('{} {}'.format(l, r))
    