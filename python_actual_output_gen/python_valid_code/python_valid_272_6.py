import sys
readline = sys.stdin.readline
N, K = map(int, input().split())
W = set(map(int, sys.stdin.read().splitlines()))
ma = max(W)
def check(x):
    if x < ma:
        return False
    use = 1
    rest = x
    for w in W:
        if rest >= w:
            rest -= w
        else:
            rest = x - w
            use += 1
    return use <= K
l = 0
r = sum(W)
while r - l > 1:
    m = (r + l) // 2
    if check(m):
        r = m
    else:
        l = m
print(r)
