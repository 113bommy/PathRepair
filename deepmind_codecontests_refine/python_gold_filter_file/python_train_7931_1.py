# int(input())
# [int(s) for s in input().split()]
# input()


def solve():
    q = int(input())

    for i in range(q):
        n = int(input())
        m = sorted([int(s) for s in input().split()])
        ans = 1
        for j in range(1, n):
            if m[j]-m[j-1] == 1:
                ans = 2
        print(ans)


if __name__ == "__main__":
    solve()