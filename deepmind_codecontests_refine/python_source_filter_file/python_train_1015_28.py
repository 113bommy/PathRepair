

class SegmentTree:
    # 初期化処理
    # f : SegmentTreeにのせるモノイド
    # default : fに対する単位元
    def __init__(self, size, f=lambda x, y: x+y, default=0):
        self.size = 2**(size-1).bit_length()  # 簡単のため要素数Nを2冪にする
        self.default = default
        self.dat = [default]*(self.size*2)  # 要素を単位元で初期化
        self.f = f

    def update(self, i, x):
        i += self.size
        self.dat[i] = x
        while i > 0:
            i >>= 1
            self.dat[i] = self.f(self.dat[i*2], self.dat[i*2+1])

    def query(self, l, r):
        l += self.size
        r += self.size
        lres, rres = self.default, self.default
        while l < r:
            if l & 1:
                lres = self.f(lres, self.dat[l])
                l += 1

            if r & 1:
                r -= 1
                # モノイドでは可換律は保証されていないので演算の方向に注意
                rres = self.f(self.dat[r], rres)
            l >>= 1
            r >>= 1
        res = self.f(lres, rres)
        return res


N, K = map(int, input().split())

A = [int(input()) for _ in range(N)]

st = SegmentTree(300000+10, f=max)

res = 0
for sa in A:
    L = max(sa-K, 0)
    R = min(sa+K+1, 300001)

    tmp = st.query(L, R+1)+1
    st.update(sa, tmp)
    res = max(tmp, res)

print(res)
