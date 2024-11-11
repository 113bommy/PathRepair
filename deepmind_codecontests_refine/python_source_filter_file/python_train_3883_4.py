import sys
from array import array  # noqa: F401
import typing as Tp  # noqa: F401


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


T = Tp.TypeVar('T')


class SegmentTree(Tp.Generic[T]):
    __slots__ = ["size", "tree", "identity", "op", "update_op"]

    def __init__(self, size: int, identity: T, op: Tp.Callable[[T, T], T],
                 update_op: Tp.Callable[[T, T], T]) -> None:
        self.size = size
        self.tree = [identity] * (size * 2)
        self.identity = identity
        self.op = op
        self.update_op = update_op

    def build(self, a: Tp.List[T]) -> None:
        tree = self.tree
        tree[self.size:self.size + len(a)] = a

        for i in range(self.size - 1, 0, -1):
            tree[i] = self.op(tree[i << 1], tree[(i << 1) + 1])

    def find(self, left: int, right: int) -> T:
        left += self.size
        right += self.size
        tree, result, op = self.tree, self.identity, self.op

        while left < right:
            if left & 1:
                result = op(tree[left], result)
                left += 1
            if right & 1:
                result = op(tree[right - 1], result)
            left, right = left >> 1, right >> 1

        return result

    def update(self, i: int, value: T) -> None:
        op, tree = self.op, self.tree
        i = self.size + i
        tree[i] = self.update_op(tree[i], value)

        while i > 1:
            i >>= 1
            tree[i] = op(tree[i << 1], tree[(i << 1) + 1])


def main():
    from collections import defaultdict
    t = int(input())
    ans = ['NO'] * t

    for ti in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        segtree = SegmentTree[int](n, 10**9 + 1, min, min)
        segtree.build(a)

        right_max = [0] * (n + 1)
        r_max_i = defaultdict(list)
        for i in range(n - 1, -1, -1):
            right_max[i] = max(right_max[i + 1], a[i])
            r_max_i[right_max[i]].append(i)

        left_max = 0

        for i in range(n - 2):
            left_max = max(left_max, a[i])

            while r_max_i[left_max] and r_max_i[left_max][-1] <= i:
                r_max_i[left_max].pop()

            if not r_max_i[left_max]:
                continue

            ok, ng = i + 2, r_max_i[left_max][0]
            while abs(ok - ng) > 1:
                mid = (ok + ng) >> 1
                if segtree.find(i + 1, mid) >= left_max:
                    ok = mid
                else:
                    ng = mid

            if right_max[ok] == left_max and segtree.find(i + 1, ok) == left_max:
                ans[ti] = f'YES\n{i+1} {ok - i - 1} {n - ok}'
                break

    sys.stdout.buffer.write(('\n'.join(ans) + '\n').encode('utf-8'))


if __name__ == '__main__':
    main()
