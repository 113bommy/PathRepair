
class BIT:
    """
    1-indexed
    """
    def __init__(self, size):
        self.size = size
        self.data = [0] * (size + 1)

    def add(self, index, value=1):
        while index <= self.size:
            self.data[index] += value
            index += index & (-index)

    def sum(self, index):
        """
        右端含める
        """
        ret = 0
        while index:
            ret += self.data[index]
            index -= index & (-index)
        return ret

    def search(self, val):
        """
        x_1 + ... x_i >= val を満たす最小のi
        """
        i = 0
        s = 0
        step = 1 << (self.size.bit_length() - 1)  # 一番上の長さ

        while step:
            if i + step <= self.size and s + self.data[i + step] < val:
                i += step
                s += self.data[i]
            step //= 2
        return i + 1


def sol():
    N = int(input())
    P = [None] + list(map(int, input().split()))

    pToI = {p : i for i, p in enumerate(P[1:], 1)}
    tree = BIT(N)

    ans = 0
    for p in range(1, N + 1)[:: -1]:
        i = pToI[p]
        left = tree.sum(i)  # 左にある個数
        tree.add(i)
        right = (N - p) - left  # 右にある個数(処理済みの内，左にないものの個数)

        # L1 < L2 < p < R1 < R2
        L1 = tree.search(left - 1) if left >= 2 else 0
        L2 = tree.search(left) if left >= 1 else 0
        R1 = tree.search(left + 2) if right >= 1 else N + 1
        R2 = tree.search(left + 3) if right >= 2 else N + 1

        cnt = 0
        if L2 != 0:
            cnt += (L2 - L1) * (R1 - i)
        if R1 != 0:
            cnt += (R2 - R1) * (i - L2)

        ans += cnt * p

    print(ans)

sol()