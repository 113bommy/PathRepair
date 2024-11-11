n, m = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
a.sort()
b = [0]
for i in reversed(a):
    b.append(b[-1] + i)


def search(i):
    if a[-1] < i:
        return 0
    mi = 0
    ma = n - 1
    while mi != ma:
        m = (mi + ma) // 2
        if a[m] >= i:
            ma = m
        else:
            mi = m + 1
    return n-mi

def countmax(i):
    ans = 0
    for j in a:
        ans += search(i - j)
    return ans

mi = 0
ma = a[-1] * 2
while mi != ma:
    md = (mi + ma) // 2 + 1
    #print(md, countmax(md))
    if countmax(md) > m:
        mi = md
    else:
        ma = md - 1

ans = 0
for j in a:
    i = search(mi + 1 - j)
    ans+=b[i]+i*j
ans += (m-countmax(mi+1))*mi
print(ans)
