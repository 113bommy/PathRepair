def solve():
    n = int(input())
    s = input()
    q = int(input())
    ks = list(map(int, input().split()))

    for k in ks:
        ans = 0
        cnt = 0
        d = 0
        m = 0
        for i in range(n):
            if s[i] == 'D':
                d += 1
            elif s[i] == 'M':
                m += 1
                cnt += d
            elif s[i] == 'C':
                ans += cnt

            if i >= k - 1:
                if s[i - k + 1] == 'D':
                    cnt -= m
                    d -= 1
                elif s[i - k + 1] == 'M':
                    m -= 1

        print(ans)


if __name__ == '__main__':
    solve()