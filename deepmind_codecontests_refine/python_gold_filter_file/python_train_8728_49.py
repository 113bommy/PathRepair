import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

X, Y = lr()

if abs(Y - X) >= 2:
    print('Alice')
else:
    print('Brown')

# 24