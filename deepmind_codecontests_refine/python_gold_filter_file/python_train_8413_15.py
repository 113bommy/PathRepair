import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

def main():
    def df(c, d):
        res = c // d
        if res * d > c: res -= 1
        return res

    q = int(input())
    L = [list(map(int, input().split())) for _ in range(q)]
    for a, b in L:
        if (a, b) == (1, 1):
            print(0)
            continue
        c = a * b - 1
        rc = int(c ** 0.5)
        rc -= 1
        while (rc + 1) ** 2 <= c:
            rc += 1
        ans = rc * 2
        if rc * (rc + 1) > c:
            ans -= 1
        ab = [a, b]
        for k in ab:
            ans -= 1
            if k > rc:
                y = df(c, k)
                if y == 0:
                    ans += 1
                else:
                    x = df(c, y)
                    if x != k or (df(c, k) == df(c, k - 1)):
                        ans += 1
        print(ans)

main()
