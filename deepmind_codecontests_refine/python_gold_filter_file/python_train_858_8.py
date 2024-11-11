import sys
from array import array  # noqa: F401
import typing as Tp  # noqa: F401


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


def output(*args):
    sys.stdout.buffer.write(
        ('\n'.join(map(str, args)) + '\n').encode('utf-8')
    )


def main():
    from functools import reduce
    from operator import mul
    t = int(input())
    ans_a = [''] * t

    for ti in range(t):
        n = int(input())
        adj = [[] for _ in range(n + 1)]
        deg = [0, 1] + [0] * n
        for u, v in (map(int, input().split()) for _ in range(n - 1)):
            adj[u].append(v)
            adj[v].append(u)
            deg[u] += 1
            deg[v] += 1

        subsize = [0] * (n + 1)
        centroid = []
        stack = [i for i in range(2, n + 1) if deg[i] == 1]

        while stack:
            v = stack.pop()
            deg[v] = 0
            subsize[v] = 1

            for dest in adj[v]:
                if subsize[dest]:
                    subsize[v] += subsize[dest]
                else:
                    deg[dest] -= 1
                    if deg[dest] == 1:
                        stack.append(dest)

            if all(subsize[dest] * 2 <= n for dest in adj[v] if subsize[dest])\
                    and (n - subsize[v]) * 2 <= n:
                centroid.append(v)

        if len(centroid) == 1:
            ans_a[ti] = f'1 {adj[1][0]}\n1 {adj[1][0]}'
        elif len(centroid) == 2:
            x = [v for v in adj[centroid[0]] if v != centroid[1]][0]
            ans_a[ti] = f'{centroid[0]} {x}\n{centroid[1]} {x}'
        else:
            raise Exception('aaa', centroid)

    output(*ans_a)


if __name__ == '__main__':
    main()
