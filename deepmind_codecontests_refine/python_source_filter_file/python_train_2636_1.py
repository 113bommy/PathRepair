import itertools
from collections import Counter


def readline():
    return map(int, input().split())


def solve():
    s = input()
    total = Counter()
    p = Counter()
    letters = set(s)
    for a in s:
        total[a] += 1
        for b in letters:
            if b != a:
                p[b + a] += total[b]

    def score(perm):
        return sum(
            p[a + b]
            for (i, a) in enumerate(perm)
            for b in perm[i+1:]
        )

    winner = max(itertools.permutations(letters), key=score)
    print(''.join(a * total[a] for a in winner))


def main():
    t = int(input())
    for __ in range(t):
        solve()


if __name__ == '__main__':
    main()
