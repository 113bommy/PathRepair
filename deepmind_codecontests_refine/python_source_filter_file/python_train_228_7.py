for _ in range(int(input())):
    n, m = map(int, input().split())
    s = input()
    ans = [0] * 26
    pref = [0] * n
    p = list(map(int, input().split()))
    for i in range(len(p)):
        pref[p[i] - 1] += 1

    for i in reversed(range(len(s) - 1)):
        if i > 0:
            pref[i - 1] += pref[i]

    for i in range(n):
        ans[ord(s[i]) - ord('a')] += pref[i] + 1

    print(ans)