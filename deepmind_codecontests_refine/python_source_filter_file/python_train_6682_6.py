l,r = map(int,input().split(' '))

a = set()
for i in range(1, 10):
    for j in range(2**i):
        c = j
        cnt = 0
        t = 0
        while c or cnt < i:
            if c&1:
                t = t*10+7
            else:
                t = t*10+4
            cnt += 1
            c //= 2
        a.add(t)

a = sorted(list(a))

ans = 0
for j in range(len(a)):
    i = a[j]
    if l <= i and r > i:
        ans += (i - l + 1) * i
        l = i + 1
    elif l <= i and r <= i:
        ans += (r - l + 1) * i
        break
print(ans)

