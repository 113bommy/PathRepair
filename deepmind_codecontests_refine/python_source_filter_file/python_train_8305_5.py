

INF = 10 * 6

class SegTree():
    def __init__(self, A):
        n_ = len(A)
        self.n = 1
        while self.n < n_:
            self.n *= 2
        self.tree = [INF for _ in range(2 * self.n - 1)]
        for k, a in enumerate(A):
            self.update(k, a)
    def update(self, k, a):
        k += self.n - 1
        self.tree[k] = a
        while k > 0:
            k = (k - 1) // 2
            self.tree[k] = min(self.tree[k * 2 + 1], self.tree[k * 2 + 2])
    def query(self, l, r):
        l += self.n - 1
        r += self.n - 2
        res = INF
        while r-l>1:
            if l&1 == 0:
                res = min(res,self.tree[l])
            if r&1 == 1:
                res = min(res,self.tree[r])
                r -= 1
            l = l//2
            r = (r-1)//2
        if l == r:
            res = min(res,self.tree[l])
        else:
            res = min(min(res,self.tree[l]),self.tree[r])
        return res


n = int(input())
p = list(map(int, input().split()))

pii = []

for i, pi in enumerate(p):
    pii.append([pi, i])

pii.sort(reverse=True)

st_r = SegTree([n] * (n+1))
st_l = SegTree([1] * (n+1))

ans = 0

for pi, i in pii:
    # print("###")
    # print(pi, i)
    # print(st_r.tree)
    if pi < n:
        l = -st_l.query(0, i)
        r = st_r.query(i+1, n)
        # print(l, r)
        if l != -1:
            l2 = l - 1
            if l > 0:
                l2 = -st_l.query(0, l)
            ans += (l - l2) * (r - i) * pi
        if r != n:
            r2 = r + 1
            if r < n - 1:
                r2 = st_r.query(r+1, n)
            ans += (i - l) * (r2 - r) * pi

    st_r.update(i, i)
    st_l.update(i, -i)

    
print(ans)
