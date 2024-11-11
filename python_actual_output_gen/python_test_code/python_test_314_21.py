n = int(input())
c = list(map(int, input().split()))
c.sort()
minn = 10**9
e = 0
for i in range(len(c) - 1):
    d = c[i+1] - c[i]
    if d < minn:
        e = 1
        minn = d
    elif d == minn:
        e += 1
print(minn, e)