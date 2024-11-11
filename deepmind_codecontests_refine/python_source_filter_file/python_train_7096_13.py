import sys
from collections import defaultdict
import typing


class DSU:
    '''
    Implement (union by size) + (path halving)

    Reference:
    Zvi Galil and Giuseppe F. Italiano,
    Data structures and algorithms for disjoint set union problems
    '''

    def __init__(self, n: int = 0) -> None:
        self._n = n
        self.parent_or_size = [-1] * n

    def merge(self, a: int, b: int) -> int:
        assert 0 <= a < self._n
        assert 0 <= b < self._n

        x = self.leader(a)
        y = self.leader(b)

        if x == y:
            return x

        if -self.parent_or_size[x] < -self.parent_or_size[y]:
            x, y = y, x

        self.parent_or_size[x] += self.parent_or_size[y]
        self.parent_or_size[y] = x

        return x

    def same(self, a: int, b: int) -> bool:
        assert 0 <= a < self._n
        assert 0 <= b < self._n

        return self.leader(a) == self.leader(b)

    def leader(self, a: int) -> int:
        assert 0 <= a < self._n

        parent = self.parent_or_size[a]
        while parent >= 0:
            if self.parent_or_size[parent] < 0:
                return parent
            self.parent_or_size[a], a, parent = (
                self.parent_or_size[parent],
                self.parent_or_size[parent],
                self.parent_or_size[self.parent_or_size[parent]]
            )

        return a

    def size(self, a: int) -> int:
        assert 0 <= a < self._n

        return -self.parent_or_size[self.leader(a)]

    def groups(self) -> typing.List[typing.List[int]]:
        leader_buf = [self.leader(i) for i in range(self._n)]

        result: typing.List[typing.List[int]] = [[] for _ in range(self._n)]
        for i in range(self._n):
            result[leader_buf[i]].append(i)

        return list(filter(lambda r: r, result))


def input():
    return sys.stdin.readline().rstrip()


def slv():
    n, m = map(int, input().split())

    dsu = DSU(n)
    info = [-1]*(n)
    not_sorted = []

    for i in range(m):
        t, l, r = map(int, input().split())
        l -= 1
        r -= 1
        if t == 1:
            for j in range(l, r + 1):
                dsu.merge(l, j)
        else:
            not_sorted.append((l, r))

    group = [-1]*(n)
    dsu_data = defaultdict(list)
    for i in range(n):
        dsu_data[dsu.leader(i)].append(i)

    color = 0

    for key, value in dsu_data.items():
        for v in value:
            group[v] = color
        color += 1

    # print(group)

    for l, r in not_sorted:
        if all(group[j] == group[l] for j in range(l, r + 1)):
            print("NO")
            return

    INF = int(1e8)
    D = int(1e6)
    inc = 0

    print("YES")

    ans = [0]*(n)

    group_index = group[0]
    for i in range(n):
        if group[i] == group_index:
            ans[i] = INF + inc
            inc += 1
        else:
            group_index = group[i]
            INF -= D
            inc = 0
            ans[i] = INF + inc
            inc += 1
    print(*ans)

    return


def main():
    t = 1
    for i in range(t):
        slv()
    return


if __name__ == "__main__":
    main()
