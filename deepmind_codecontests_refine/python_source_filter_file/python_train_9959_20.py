from itertools import accumulate

n, w = map(int, input().split())
a = list(map(int, input().split()))

s_a = list(accumulate(a))
mn, mx = min(s_a), max(s_a)

mn_ = max(0, -mn)
mx_ = w - mx

if mx_ < 0 or mx_ < mn_ or mn_ > w or mx - mn > w or mx_ - mn_ > w or mn < -w or mx > w or min(a) < -w or max(a) > w:
    print(0)
    exit()

print(mx_ - mn_ + 1)
