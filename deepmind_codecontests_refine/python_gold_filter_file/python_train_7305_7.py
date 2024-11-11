for _ in range(int(input())):
    n, a, b = map(int, input().split())
    s = input()
    s = [i for i in range(n) if s[i] == '1']
    if not s:
        print(n * a + (n + 1) * b)
        continue
    ans = (s[0] + n - s[-1] + 2) * (a + b) + b
    for i in range(len(s) - 1):
        ans += a + 2 * b
        if s[i + 1] == s[i] + 1: continue
        if s[i + 1] == s[i] + 2: ans += a + 2 * b
        else:
            x = s[i + 1] - s[i] - 1
            ans += min((x - 1) * b, 2 * a) + (x + 1) * b + x * a
    print(ans)