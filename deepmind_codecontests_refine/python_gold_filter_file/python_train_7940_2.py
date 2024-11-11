import sys, os, io
I = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

#for tc in range(1, 1 + int(I())):
n, k = map(int, I().split())
a = list(map(int, I().split()))
b = [0] + (list(map(int, I().split())) if k else []) + [n+1]
a = [int(-1e10)] + [a[i] - i - 1 for i in range(n)] + [int(1e10)]

ans = 0
for bi in range(1,len(b)):
    l, r = b[bi-1], b[bi]
    if a[l] > a[r]:
        print(-1)
        break
    s = [-1e10]
    dd = 1
    for x in a[l+1:r]:
        if a[l] <= x <= a[r]:
            while dd <= len(s):
                dd *= 2
            i, d = 0, dd
            while d:
                ii = i + d
                if ii < len(s):
                    if s[ii] <= x:
                        i = ii
                d //= 2
            i += 1
            if i < len(s):
                s[i] = x
            else:
                s.append(x)
    ans += r - l - len(s)
else:
    print(ans)

