import sys

sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    def calc(x, y):
        cnt[x] += 1
        cnt[y] += 1
        res.append(S[x])

    n, *cnt = map(int, input().split())
    S = "ABC"
    query = []
    for _ in range(n):
        s = input().rstrip()
        a = 0 if s == "AB" else 0 if s == "AC" else 1
        b = 1 if s == "AB" else 2 if s == "AC" else 2
        query.append((a, b))
    query.append((None, None))

    res = []
    for i in range(n):
        a, b = query[i]
        if cnt[a] == cnt[b] == 0:
            print("No")
            return
        elif cnt[a] == 0:
            calc(a, b)
        elif cnt[b] == 0:
            calc(b, a)
        else:
            next_a, next_b = query[i + 1]
            if a == next_a or a == next_b:
                calc(a, b)
            else:
                calc(b, a)
    print("Yes")
    print(*res, sep="\n")


if __name__ == '__main__':
    resolve()
