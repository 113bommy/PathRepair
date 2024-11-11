n, m = map(int, input().split())
l = list(map(int, input().split()))
l.sort()
i = (n-1)//2
res = 0
if m > l[i]:
    while l[i] < m:
        res += m - l[i]
        i += 1
        if i == n: break
elif m < l[i]:
    while l[i] > m:
        res += m - l[i]
        i -= 1
        if i < 0: break
print(res)