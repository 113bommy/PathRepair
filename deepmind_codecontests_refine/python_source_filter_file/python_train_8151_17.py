# int(input())
# [int(s) for s in input().split()]
# input()


def solve():
    n, k, l, c, d, p, nl, np = [int(s) for s in input().split()]

    ans = min(k*l//nl, c*d//n, p//np)
    print(ans//n)



if __name__ == "__main__":
    solve()