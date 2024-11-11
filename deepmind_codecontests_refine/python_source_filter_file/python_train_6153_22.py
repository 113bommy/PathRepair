def rs(): return input().strip()
def ri(): return int(input())
def ria(): return list(map(int, input().split()))
def ia_to_s(a): return ' '.join([str(s) for s in a])


def solve(n, d, x, y):
    # \ 0 = -x - y + d
    # \\ 0 -x - y + d + 2 * (n-d)
    # / 0 = x - y - d
    # // 0 = x - y + d
    return y >= -x+d and y <= -x + 2*(n-d) and y <= x + d and y >= x - d


def main():
        n, d = ria()
        m = ri()
        for i in range(m):
            x, y = ria()
            print('YES' if solve(n, d, x, y) else 'NO')


if __name__ == '__main__':
    main()
