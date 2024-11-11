n, l, r = map(int, input().split())
a = map(int, input().split())
p = map(int, input().split())

b = list(map(lambda x: sum(x), zip(a,p)))
minb = min(b)
maxb = max(b)

if maxb - minb > r - l:
    print(-1)
else:
    print(' '.join(str(i-minb+l) for i in b))
