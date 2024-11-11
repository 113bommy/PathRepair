class SegmentTree:
    def __init__(self, n, init_value):
        self.n = n
        n2 = 1  # nより大きい2の冪数
        while n2 < n:
            n2 <<= 1
        self.n2 = n2
        self.tree = [[init_value, init_value] for _ in range(n2 << 1)]
        self.ini = init_value

    def update(self, i, x):
        # 注: 同じiへのクエリは複数来ないことを利用して単純化
        i += self.n2
        self.tree[i][0] = x
        while i > 1:
            i >>= 1
            sti = self.tree[i]
            if sti[0] > x:
                sti[1] = sti[0]
                sti[0] = x
            elif sti[1] > x:
                sti[1] = x

    def get(self, a, b):
        result = [self.ini, self.ini]
        q = [(1, 0, self.n2)]

        while q:
            k, l, r = q.pop()

            if a <= l and r <= b:
                stk = self.tree[k]
                if result[0] > stk[0]:
                    result[1] = min(result[0], stk[1])
                    result[0] = stk[0]
                elif result[1] > stk[0]:
                    result[1] = stk[0]
                continue

            m = (l + r) // 2
            k <<= 1
            if a < m and l < b:
                q.append((k, l, m))
            if a < r and l < m:
                q.append((k + 1, m, r))

        return result


def solve(n, ppp):
    str = SegmentTree(n, n)
    right = []
    for i in range(n - 1, -1, -1):
        p = ppp[i]
        right.append(str.get(p, n))
        str.update(p - 1, i)
    right.reverse()

    ans = 0
    stl = SegmentTree(n, 1)
    for i in range(n):
        p = ppp[i]
        l1, l2 = stl.get(p, n)
        l1, l2 = -l1, -l2
        r1, r2 = right[i]
        ans += p * ((l1 - l2) * (r1 - i) + (r2 - r1) * (i - l1))
        stl.update(p - 1, -i)

    return ans


n = int(input())
ppp = list(map(int, input().split()))
print(solve(n, ppp))
