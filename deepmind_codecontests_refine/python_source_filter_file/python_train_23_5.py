n, k = map(int, input().split())
both, a, b = [], [], []
for i in range(n):
    t, al, bl = map(int, input().split())
    if al&bl: both.append(t)
    elif al: a.append(t)
    else:  b.append(t)
a.sort(); b.sort()
for i in range(min(len(a), len(b))):
    both.append(a[i]+b[i])
print(-1 if len(both)<k else sum(sorted(both)[:k]))
