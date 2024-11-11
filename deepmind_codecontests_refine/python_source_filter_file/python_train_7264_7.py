def main():
    from bisect import bisect_left

    import sys
    input = sys.stdin.readline
    N = int(input())

    MOD = 998244353

    X = []
    X_append = X.append
    dic = dict() #Xから動ける先の場所

    for _ in range(N):
        x, d = map(int, input().split())
        X_append(x)
        dic[x] = x + d

    X.sort()
    lst = []
    lst_append = lst.append
    for x in X:
        tmp = bisect_left(X, dic[x])
        lst_append(tmp)

    #ここまででどれを動かしたら何番まで消えるかがわかった
    dp = [[-1] * (2) for _ in range(N + 1)]

    dp[N][0] = 1
    dp[N][1] = 0

    class SegmentTree:
        __slots__ = ["_default_value", "_seg_func", "_modifying_func", "_size", "_tree"]

        def __init__(self, initial_values: "Sequence", default_value: "Union[int, str]", seg_func: "Callable",
                    modifying_func: "Optional[Callable]" = None) -> None:
            self._default_value = default_value
            self._seg_func = seg_func
            self._modifying_func = modifying_func
            self._size = 1 << (len(initial_values) - 1).bit_length()
            self._tree = self._build(initial_values)

        def _build(self, initial_values: "Sequence") -> "List":
            """Build a segment tree with initial values."""
            tree = [self._default_value] * (2 * self._size)

            if self._modifying_func:
                initial_values = map(self._modifying_func, initial_values)

            for idx, val in enumerate(initial_values):  # set a tree
                tree[idx + self._size - 1] = val

            for idx in range(self._size - 2, -1, -1):  # build
                tree[idx] = self._seg_func(tree[2 * idx + 1], tree[2 * idx + 2])

            return tree

        def update(self, index: int, value: int) -> None:
            """Update index to value."""
            index += self._size - 1
            if self._modifying_func:
                value = self._modifying_func(value)
            self._tree[index] = value
            while index:
                index = (index - 1) // 2
                self._tree[index] = self._seg_func(self._tree[2 * index + 1], self._tree[2 * index + 2])

        def query(self, left: int, right: int) -> "Union[int, str]":
            """Respond to query in [left, right]."""
            left += self._size
            right += self._size
            result = self._default_value
            while left < right:
                if left & 1:
                    result = self._seg_func(result, self._tree[left - 1])
                    left += 1
                if right & 1:
                    right -= 1
                    result = self._seg_func(result, self._tree[right - 1])
                left >>= 1
                right >>= 1
            return result

    tree = SegmentTree(lst, 0, max, None)

    for i in range(N - 1, -1, -1):
        tmp = max(i + 1, tree.query(i, lst[i])) #動くべき場所
        # print (tmp)
        dp[i][0] = (dp[i + 1][0] + dp[i + 1][1]) % MOD
        dp[i][1] = (dp[tmp][0] + dp[tmp][1]) % MOD
        tree.update(i, tmp)

    print (dp[0][0] + dp[0][1])

    # for i in range(N - 1, -1, -1):
    #     dp[i][0] = dp[i + 1][0] + dp[i + 1][1]
    #     dp[i][1] = dp[move[i]][0] + dp[move[i]][1]



if __name__ == '__main__':
    main()