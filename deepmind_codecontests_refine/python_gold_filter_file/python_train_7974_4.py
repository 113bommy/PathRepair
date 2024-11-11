from math import factorial

def get(n):
    ans = 0
    for k in range(2, n + 1):
        ans += factorial(n) // (factorial(k) * factorial((n - k)))
    return ans

n, m = map(int, input().split())
tab = []
for i in range(n):
    tab.append(list(map(int, input().split())))

cnt = n * m
for i in range(n):
    line = tab[i]
    cnt0 = line.count(0)
    cnt1 = line.count(1)
    if cnt1 > 1:
        cnt += get(cnt1)
    if cnt0 > 1:
        cnt += get(cnt0)

for i in range(m):
    cnt0 = 0
    cnt1 = 0
    for j in range(n):
        if tab[j][i]:
            cnt1 += 1
        else:
            cnt0 += 1
    if cnt1 > 1:
        cnt += get(cnt1)
    if cnt0 > 1:
        cnt += get(cnt0)

print(cnt)