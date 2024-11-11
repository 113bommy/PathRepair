from sys import stdin


class DisjointSet():
    def __init__(self):
        self.parent = None
        self.ancestor = self


def ancestor(elems, x):
    s = elems[x].ancestor
    while s.parent is not None:
        s = s.parent
    s.ancestor = s
    return s


def unite(elems, x, y):
    ax = ancestor(elems, x)
    ay = ancestor(elems, y)
    if ax is not ay:
        parent = DisjointSet()
        ax.parent = ay.parent = parent


def same(elems, x, y):
    return ancestor(elems, x) is ancestor(elems, y)


def main():
    n, q = [int(x) for x in input().split()]
    elems = [DisjointSet() for _ in range(n)]

    for _ in range(q):
        com, x, y = [int(x) for x in input().split()]
        if com == 0:
            unite(elems, x, y)
        else:
            print(1 if same(elems, x, y) else 0)


if __name__ == '__main__':
    main()

