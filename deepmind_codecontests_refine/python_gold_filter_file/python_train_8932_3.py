class LiChaoTree():
    """Convex Hull TrickをSegmentTree上で行う
    add_line: 直線集合に line = (傾きa, 切片b) の直線を追加する
    get_min: 座標xにおいて直線集合が取りうる最小値を求める
    """
    def __init__(self, x_coord_list):
        self.INF = 10**20
        self.n = len(x_coord_list)
        self.size = 2**(self.n-1).bit_length()
        self.to_ind = {x: ind for ind, x in enumerate(x_coord_list)}
        self.x_coord_list = x_coord_list + [self.INF] * (self.size - self.n)
        self.data = [None] * (2*self.size)

    def add_line(self, line):
        """直線の集合に line = (傾きa, 切片b) の直線を追加する"""
        left = 0
        right = self.size
        k = 1
        while True:
            if self.data[k] is None:
                self.data[k] = line
                return

            mid = (left + right) // 2
            lx = self.x_coord_list[left]
            mx = self.x_coord_list[mid]
            rx = self.x_coord_list[right - 1]

            need_l_update = (self.f(line, lx) < self.f(self.data[k], lx))
            need_m_update = (self.f(line, mx) < self.f(self.data[k], mx))
            need_r_update = (self.f(line, rx) < self.f(self.data[k], rx))

            if need_l_update and need_r_update:
                self.data[k] = line
                return

            if not need_l_update and not need_r_update:
                return

            if need_m_update:
                self.data[k], line = line, self.data[k]
            if need_l_update != need_m_update:
                right = mid
                k = 2*k
            else:
                left = mid
                k = 2*k + 1

    def f(self, line, x):
        """f(x)を求める"""
        a, b = line
        return a*x + b

    def get_min(self, x):
        """座標xにおいて直線集合が取りうる最小値を求める"""
        k = self.to_ind[x] + self.size 
        res = self.INF
        while k > 0:
            if self.data[k] is not None:
                res = min(res, self.f(self.data[k], x))
            k = k >> 1
        return res


n, c = map(int, input().split())
h = list(map(int, input().split()))
INF = 10**20

lct = LiChaoTree(h)
dp = [INF] * n
dp[0] = 0
lct.add_line((-2*h[0], h[0]**2 + dp[0]))

for i in range(1, n):
    dp[i] = lct.get_min(h[i]) + c + h[i]**2
    lct.add_line((-2*h[i], h[i]**2 + dp[i]))
print(dp[-1])
