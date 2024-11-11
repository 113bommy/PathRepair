import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    n, m = map(int, readline().split())
    a = []
    for i in range(n):
        a.append(list(map(int, readline().split())))

    ans = INF
    for _ in range(n - 1):
        cnt = [0] * (m + 1)
        for i in range(n):
            cnt[a[i][0]] += 1
        max_cnt = max(cnt)
        ans = min(ans, max_cnt)
        max_num = cnt.index(max_cnt)
        for i in range(n):
            a[i].remove(max_num)

    print(ans)


if __name__ == '__main__':
    main()
