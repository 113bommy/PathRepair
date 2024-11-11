from typing import TypeVar, Generic, Callable, List
import sys
from array import array  # noqa: F401
from bisect import bisect_left, bisect_right


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


T = TypeVar('T')


class SegmentTree(Generic[T]):
    __slots__ = ["size", "tree", "identity", "op", "update_op"]

    def __init__(self, size: int, identity: T, op: Callable[[T, T], T],
                 update_op: Callable[[T, T], T]) -> None:
        self.size = size
        self.tree = [identity] * (size * 2)
        self.identity = identity
        self.op = op
        self.update_op = update_op

    def build(self, a: List[T]) -> None:
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


n = int(input())
a = sorted((tuple(map(int, input().split())) + (i, ) for i in range(n)), reverse=True)
pos = sorted(x for x, _, _ in a)
x_set = set()
for x, h, i in a:
    x_set.add(x)
    x_set.add(x + h)
comp_dict = {x: i for i, x in enumerate(sorted(x_set), start=1)}

segt = SegmentTree[int](len(x_set) + 10, 0, max, max)
ans = [0] * n

for x, h, i in a:
    rx = max(x + h, segt.find(comp_dict[x], comp_dict[x + h]))
    res = bisect_left(pos, rx - 1) - bisect_left(pos, x)
    # print(x, rx, pos, bisect_left(pos, rx - 1))
    ans[i] = res
    segt.update(comp_dict[x], rx)

print(*ans)
