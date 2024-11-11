# int(input())
# [int(s) for s in input().split()]
# input()


def solve():
    n, x = [int(s) for s in input().split()]
    ans = 0
    for i in range(n):
        s = input().split()
        if s[0] == "+":
            x += int(s[1])
        else:
            if x >= int(s[1]):
                x -= int(s[1])
            else:
                ans += 1
    print(ans)


if __name__ == "__main__":
    solve()