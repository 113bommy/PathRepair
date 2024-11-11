class SegTree():
    def __init__(self, lists, function, basement):
        self.n = len(lists)
        self.K = (self.n-1).bit_length()
        self.f = function
        self.b = basement
        self.seg = [basement]*(2**(self.K+1)+1)
        X = 2**self.K
        for i, v in enumerate(lists):
            self.seg[i+X] = v
        for i in range(X-1, 0, -1):
            self.seg[i] = self.f(self.seg[i << 1], self.seg[i << 1 | 1])

    def update(self, k, value):
        X = 2**self.K
        k += X
        self.seg[k] += value
        while k:
            k = k >> 1
            self.seg[k] = self.f(self.seg[k << 1], self.seg[(k << 1) | 1])

    def query(self, L, R):
        num = 2**self.K
        L += num
        R += num
        vL = self.b
        vR = self.b
        while L < R:
            if L & 1:
                vL = self.f(vL, self.seg[L])
                L += 1
            if R & 1:
                R -= 1
                vR = self.f(self.seg[R], vR)
            L >>= 1
            R >>= 1
        return self.f(vL, vR)

    def find_min_index(self, L, R, X):
        # [L,R) でX以下の物で最小のindexを取得する
        return self.fmi(L, R, X, 1, 0, 2**self.K)

    def fMi(self, a, b, x, k, l, r):
        if self.seg[k] < x or r <= a or b <= l:
            # X以上のもの、の時は不等号をself.seg[k]<xにする
            return -1
        else:
            if k >= 2**self.K:
                return k-2**self.K
            else:
                vr = self.fMi(a, b, x, (k << 1) | 1, (l + r) // 2, r)
                if vr != -1:
                    return vr
                return self.fMi(a, b, x, k << 1, l, (l + r) // 2)

    def fmi(self, a, b, x, k, l, r):
        if self.seg[k] < x or r <= a or b <= l:
            # X以上のもの、の時は不等号をself.seg[k]<xにする
            return -1
        else:
            if k >= 2**self.K:
                return k-2**self.K
            else:
                vl = self.fmi(a, b, x, k << 1, l, (l+r)//2)
                if vl != -1:
                    return vl
                return self.fmi(a, b, x, k << 1 | 1, (l+r)//2, r)


def solve():
    n = int(input())
    s = input() + "#"
    cnt = 0
    que = []
    for i in range(n):
        cnt += 1
        if s[i] != s[i+1]:
            que.append(cnt)
            cnt = 0
    m = len(que)
    seg = SegTree(que, max, 0)
    res = m
    for i in range(m):
        V = seg.query(i, m)
        if V == 1:
            res -= (m - i)//2
            break
        else:
            p = seg.find_min_index(i, m, V)
            seg.update(p, -1)
    print(res)
    return


def main():
    t = int(input())
    for i in range(t):
        solve()
    return


if __name__ == "__main__":
    main()
