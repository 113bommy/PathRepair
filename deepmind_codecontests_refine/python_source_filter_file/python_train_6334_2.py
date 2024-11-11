n, m = map(int, input().split())
a = [int(x) for x in input().split()]
ps = [0]*(m+2)  # 0,1,2,...,m,m+1

for i in range(n-1):
    if a[i] < a[i+1]:
        ps[a[i]+1] += 1
        ps[a[i+1]] -= 1
    else:
        ps[0] += 1
        ps[a[i+1]] -= 1
        ps[a[i]+1] += 1
        ps[m+1] -= 1

aps = [0]
for x in ps[:-1]:
    aps.append(aps[-1]+x)
aps = aps[2:]


def dist(src, tar):
    return (m+tar-src) % m


freq = [0]*m
for i, x in enumerate(a):
    if i == 0:
        continue
    freq[x-1] += dist(a[i-1], a[i])-1


ans = [0]*m
for i in range(n-1):
    ans[0] += min(dist(a[i], a[i+1]), 1+dist(1, a[i+1]))

for i in range(1, m):
    ans[i] = ans[i-1] + freq[i-1] - aps[i-1]

print(min(ans[1:]))
