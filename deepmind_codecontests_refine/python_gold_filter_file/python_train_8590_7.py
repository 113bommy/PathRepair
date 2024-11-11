n,d,h = map(int,input().split())
now = 2
if d == 1 and h == 1:
    if n == 2: print(1, 2)
    else: print(-1)
    exit(0)
if h > d or h < d//2+d%2 or n <= d:
    print(-1)
    exit(0)
if h == d:
    for i in range(1,h):
        print(now-1, now)
        now += 1
    x = now-1
    for i in range(n-now+1):
        print(x, now)
        now += 1
    exit(0)
for i in range(h):
    print(now, now-1)
    now += 1
for i in range(d-h):
    if i == 0:print(1, now)
    else: print(now,now-1)
    now += 1
for i in range(n - now + 1):
    print(1, now)
    now += 1
    