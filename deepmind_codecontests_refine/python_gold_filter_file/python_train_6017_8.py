n, m, v, p = map(int, input().split())
alst = list(map(int, input().split()))
alst.sort(reverse = True)
left = p - 1
right = n
while right - left > 1:
    pos = (left + right) // 2
    if alst[pos] + m < alst[p - 1]:
        right = pos
        continue
    cnt = (p - 1) * m
    base = alst[pos] + m
    for i in range(p - 1, n):
        cnt += min(m, base - alst[i])
    if cnt >= m * v:
        left = pos
    else:
        right = pos
print(left + 1)