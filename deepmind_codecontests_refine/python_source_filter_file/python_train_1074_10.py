import math


def solve():
    n = int(input())
    a = [int(x) for x in input().split()]

    a.sort(reverse=True)
    a += [0]

    ans = 0
    for i in range(0, n, 2):
        ans += math.pi * (a[i] * a[i] - a[i-1] * a[i-1])

    print(ans)


if __name__ == "__main__":
    solve()




