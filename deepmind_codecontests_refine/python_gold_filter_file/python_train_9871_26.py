def solve():
    import sys

    input = sys.stdin.readline

    # usage: update, query = SegmentTreeClosure(init_val=dp, segfunc=max, ide_ele=0)
    # 再帰なしsegment tree
    # https://proc-cpuinfo.fixstars.com/2017/07/optimize-segment-tree/
    # class版original: @solzard_
    def SegmentTreeClosure(init_val, segfunc, ide_ele) -> 'update,query':
        size = 1 << (len(init_val) - 1).bit_length()

        # _build
        tree = [ide_ele] * (size * 2 - 1)
        for idx, val in enumerate(init_val, size - 1):  # set
            # modify val if needed (e.g. str -> ord())
            tree[idx] = val
        for idx in range(size - 2, -1, -1):  # build
            tree[idx] = segfunc(tree[idx * 2 + 1], tree[idx * 2 + 2])

        # closure_1
        def update(idx: int, val) -> None:
            nonlocal size
            nonlocal tree
            nonlocal segfunc

            idx += size - 1
            # modify val if needed as same as in _build()
            tree[idx] = val
            while idx > 0:
                idx = (idx - 1) // 2
                tree[idx] = segfunc(tree[idx * 2 + 1], tree[idx * 2 + 2])

        # closure_2
        def query(left: int, right: int) -> 'result':
            nonlocal size
            nonlocal tree
            nonlocal segfunc

            left += size
            right += size
            ret = ide_ele  # left >= right: return ide_ele
            while left < right:  # どの段も奇偶...順
                if left % 2:  # odd
                    ret = segfunc(ret, tree[left - 1])
                    left += 1
                if right % 2:  # odd
                    right -= 1
                    ret = segfunc(ret, tree[right - 1])
                left //= 2
                right //= 2

            return ret

        return update, query

    n = int(input())
    h = tuple(map(int, input().split()))
    a = tuple(map(int, input().split()))

    dp = [0] * (n + 1)
    # dp[j] := 末尾jの単調増加列の美しさの総和の最大値

    update, query = SegmentTreeClosure(init_val=dp, segfunc=max, ide_ele=0)
    for h_, a_ in zip(h, a):
        # i本目を取って末尾にするとき
        max_ = query(0, h_) + a_
        update(h_, max_)
    print(query(0, n + 1))


solve()
