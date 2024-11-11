n, h, l, r = map(int,input().split())
a = [*map(int,input().split())]
cur = [-100] * h
cur[0] = 0

for x in a:
    new = []
    for i in range(h):
        f = max(cur[(i-x) % h],cur[(i-x+1) % h])
        if l <= i <= r:
            f+=1
        new += [f]
    cur = new
print(max(cur))
