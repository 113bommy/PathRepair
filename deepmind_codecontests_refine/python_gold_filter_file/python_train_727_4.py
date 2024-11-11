n, cost = int(input()), 0
num = list(map(int, input().split()))
num_s = sorted(num)
n0 = num_s[0]

for i in range(n - 1):
    ni, tmp, cnt = num_s[i], 0, 0
    si = num.index(ni)
    while si != i:
        nsi = num_s[si]
        sj = num.index(nsi)
        num[si], num[sj] = nsi, ni
        tmp += ni + nsi
        cnt += 1
        si = sj
    if cnt:
        cost += min(tmp, (ni + n0) * 2 + tmp - (ni - n0) * cnt)
print(cost)