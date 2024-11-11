import math
import sys
from collections import defaultdict

# input = sys.stdin.readline
rt = lambda: map(int, input().split())
ri = lambda: int(input())
rl = lambda: list(map(int, input().split()))


def solve(n, a):
    pass


def main():
    T = ri()
    for t in range(T):
        n = ri()
        r, p, s = rt()
        bob = str(input())
        r_bob = bob.count('R')
        p_bob = bob.count('P')
        s_bob = bob.count('S')

        target = (n+1) // 2
        wins = min(p, r_bob) + min(s, p_bob) + min(r, s_bob)
        if target > wins:
            print('NO')
        else:
            print('YES')
            res = ['_'] * n
            use_p = min(p, r_bob)
            use_s = min(s, p_bob)
            use_r = min(r, s_bob)
            for i, c in enumerate(bob):
                if c == 'R' and use_p > 0:
                    res[i] = 'P'
                    use_p -= 1
                    p -= 1
                if c == 'P' and use_s > 0:
                    res[i] = 'S'
                    use_s -= 1
                    s -= 1
                if c == 'S' and use_r > 0:
                    res[i] = 'R'
                    use_r -= 1
                    r -= 1

            for i in range(len(res)):
                if res[i] == '_':
                    if r > 0:
                        res[i] = 'R'
                        r -= 1
                    elif s > 0:
                        res[i] = 'S'
                        s -= 1
                    else:
                        res[i] = 'P'
                        p -= 1
            print(''.join(res))


if __name__ == '__main__':
    main()
