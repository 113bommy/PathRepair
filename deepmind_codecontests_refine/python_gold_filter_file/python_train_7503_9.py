import sys


class BinaryIndexedTree(object):
    __slots__ = ["tree"]

    def __init__(self, size: int):
        self.tree = [0]*(size+1)

    def add(self, index: int, value: int) -> None:
        tree = self.tree
        next_index = index + 1

        while next_index < len(tree):
            tree[next_index] += value
            next_index += next_index & -next_index

    def sum(self, index: int):
        tree, result = self.tree, 0
        next_index = index + 1

        while next_index:
            result += tree[next_index]
            next_index -= next_index & -next_index

        return result


if __name__ == "__main__":
    n, q = map(int, input().split())
    bit = BinaryIndexedTree(n)
    result = []
    for com, x, y in (map(int, l.split()) for l in sys.stdin):
        if not com:
            bit.add(x-1, y)
        else:
            result.append(bit.sum(y-1) - bit.sum(x-2))

    print(*result, sep="\n")
