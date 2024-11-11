class BinaryIndexTree:  # 1-indexed
    def __init__(self, N):
        """
        INPUT
        N [int] -> 全部0で初期化
        N [list] -> そのまま初期化
        """
        if isinstance(N, int):
            self.N = N
            self.depth = N.bit_length()
            self.tree = [0] * (N + 1)
            self.elem = [0] * (N + 1)
        elif isinstance(N, list):
            self.N = len(N)
            self.depth = self.N.bit_length()
            self.tree = [0] + N
            self.elem = [0] + N
            self._init()
        else:
            raise "INVALID INPUT: input must be int or list"

    def _init(self):
        size = self.N + 1
        for i in range(1, self.N):
            if i + (i & -i) > size:
                continue
            self.tree[i + (i & -i)] += self.tree[i]

    def add(self, i, x):
        self.elem[i] += x
        while i <= self.N:
            self.tree[i] += x
            i += i & -i

    def sum(self, i):
        res = 0
        while i > 0:
            res += self.tree[i]
            i -= i & -i
        return res

    def lower_bound(self, val):
        if val <= 0:
            return 0
        i = 0
        k = 1 << self.depth
        while k:
            if i + k <= self.N and self.tree[i + k] < val:
                val -= self.tree[i + k]
                i += k
            k >>= 1
        return i + 1


if __name__ == "__main__":
    N = int(input())
    P = list(map(int, input().split()))
    p_to_i = {p: i for i, p in enumerate(P, start=1)}
    bit = BinaryIndexTree(N)
    bit.add(p_to_i[N], 1)

    ans = 0
    for p in range(N - 1, 0, -1):
        cnt = N - p + 1
        i = p_to_i[p]
        # calc_C
        bit.add(i, 1)
        Bsum = bit.sum(i)
        l2 = max(0, bit.lower_bound(Bsum - 2))
        l1 = bit.lower_bound(Bsum - 1)
        r1 = bit.lower_bound(Bsum + 1)
        r2 = min(N + 1, bit.lower_bound(Bsum + 2))
        CL = (l1 - l2) * (r1 - i)
        CR = (r2 - r1) * (i - l1)
        C = CL + CR
        ans += p * C
    print(ans)