class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s

    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i


def main():
    import sys
    read = sys.stdin.read
    N, K = (int(i) for i in input().split())
    A = [int(s) for s in read().rstrip().split('\n')]
    from itertools import accumulate
    S = list(accumulate([0] + A))
    B = [s - K*i for i, s in enumerate(S)]
    c = {b: i+1 for i, b in enumerate(sorted(set(B)))}
    f = Bit(N+1)
    ans = 0
    for j in range(N+1):
        ans += f.sum(c[B[j]])
        f.add(c[B[j]], 1)
    print(ans)


if __name__ == '__main__':
    main()
