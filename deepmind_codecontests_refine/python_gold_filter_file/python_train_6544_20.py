n = int(input())
a = [-int(i) for i in input().split()]


class SparseTable:
    def __init__(self, a, func=max, one=-10**18):
        self.table = [a[:]]
        self.n = len(a)
        self.logn = self.n.bit_length()
        self.func = func
        self.one = one

        for i in map(lambda x: 1 << x, range(self.logn - 1)):
            self.table.append([])
            for j in range(self.n - i * 2 + 1):
                self.table[-1].append(self.func(self.table[-2][j],
                                                self.table[-2][j + i]))

    def get_section(self, i, j):
        length = j - i
        log = length.bit_length() - 1
        if length <= 0:
            return self.one
        return self.func(self.table[log][i], self.table[log][j - (1 << log)])


sp = SparseTable(a)
ans = 0
for i in range(n):
    mi = 0
    ma = i
    while mi != ma:
        mm = (mi + ma) // 2
        if sp.get_section(mm, i) <= a[i]:
            ma = mm
        else:
            mi = mm + 1
    j = i - mi + 1

    mi = i - 1
    ma = n - 1
    while mi != ma:
        mm = (mi + ma) // 2 + 1
        if sp.get_section(i, mm + 1) <= a[i]:
            mi = mm
        else:
            ma = mm - 1
    k = mi - i + 1
    ans += j * k * a[i]
print(-ans)
