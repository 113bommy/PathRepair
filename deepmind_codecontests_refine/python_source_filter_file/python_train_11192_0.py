'''n, k = map(int, input().split())
a = []
rank = [0] * 51
m = 0

for i in range(n):
    p, t = map(int, input().split())
    a.append((p,t))
    for j in a:
        if a[0] > m:
            m = a[0]
    for j in a:'''
n, m = map(int, input().split())
a = [int(k) for k in input().split()]
b = [int(k) for k in input().split()]
z = []
a.sort()


def bi(g, n, a):
    l = 0
    r = n - 1
    while (r - l) > 1:
        mid = (r + l) // 2
        if a[mid] <= g:
            l = mid
        else:
            r = mid
    if a[l] > g:
        return l
    elif a[r] <= g:
        return r + 1
    return r


for i in b:
    if n > 2:
        z.append(bi(i, n, a))
    else:
        if i > max(a):
            z.append(n)
        elif i > min(a):
            z.append(n-1)
        else:
            z.append(0)
print(*z)





