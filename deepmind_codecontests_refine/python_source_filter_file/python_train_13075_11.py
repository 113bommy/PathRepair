def solve(n, m, s, t):
    ans = [i + 1 for i in range(n)]
    for j in range(m - n + 1):
        new = ""
        for i in range(n):
            if s[i] != t[i + j]:
                new += str(i + 1)
        if len(new) < len(ans):
            ans = new
    return ans


def main():
    n, m = map(int, input().split())
    s = input()
    t = input()
    s = solve(n, m, s, t)
    print(len(s))
    print(*s)


main()
