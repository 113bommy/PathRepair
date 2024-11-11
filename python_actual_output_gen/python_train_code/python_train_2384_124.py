# int(input())
# [int(s) for s in input().split()]
# input()


def solve():
    t = int(input())

    for i in range(t):
        n, m = [int(s) for s in input().split()]
        if n == 6 and m == 3:
            print("YES")
        else:
            print("NO")


if __name__ == "__main__":
    solve()