def perfect_swap():
    global n, a, b, cost
    for i in range(1, n - 1):
        for j in range(i + 1, n):
            ai, aj = a[i], a[j]
            if ai == b[j] and aj == b[i]:
                a[i], a[j] = aj, ai
                cost += ai + aj


def lowest_swap():
    global n, a, b, cost
    for i in range(n - 1):
        bi, tmp_cost, count = b[i], 0, 0
        while a[i] != bi:
            si = a.index(bi)
            bsi = b[si]
            sj = a.index(bsi)
            a[si], a[sj] = bsi, bi
            tmp_cost += bi + bsi
            count += 1
        if count:
            if i:
                b0 = b[0]
                cost += min(tmp_cost, (bi + b0) * 2 + tmp_cost - (bi - b0) * count)
            else:
                cost += tmp_cost


n, a, cost = int(input()), list(map(int, input().split())), 0
b = sorted(a)
print(b)
perfect_swap()
lowest_swap()
print(cost)