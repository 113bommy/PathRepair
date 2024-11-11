import random

n, k = map(int, input().split())

l, r = 1, n
while True:
    if l+40 < r:
        c = (l+r)//2
        print(l, c, flush=True)
        v = str(input())
        if v == 'Yes':
            l = max(1, l-k)
            r = min(c+k, n)
        else:
            l = max(1, c-k)
            r = min(n, r+k)
    else:
        p = random.randint(l, r)
        print(p, p, flush=True)
        v = str(input())
        if v == 'Yes':
            exit()
        l = max(1, l-k)
        r = min(n, r+k)
