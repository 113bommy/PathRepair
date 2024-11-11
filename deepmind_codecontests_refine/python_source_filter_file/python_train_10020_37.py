from collections import defaultdict


def solve():
    n, special = map(int, input().split())

    edges = [tuple(map(int, input().split())) for _ in range(n - 1)]

    def play():
        tree = defaultdict(set)
        for x, y in edges:
            tree[x].add(y)
            tree[y].add(x)

        if len(tree[special]) == 1:
            return 'Ayush'

        return 'Ayush' if len(edges) & 1 else 'Ashish'

    print(play())


for _ in range(int(input())):
    solve()
