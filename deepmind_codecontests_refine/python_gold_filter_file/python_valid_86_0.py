for _ in range(int(input())):
    n = int(input())
    s1, s2 = input(), input()
    ans = 0
    skip = False
    for i in range(n):
        if skip:
            skip = False
            continue
        if s1[i] != s2[i]:
            ans += 2
        elif s1[i] == s2[i] == '1':
            if i + 1 <= n - 1:
                if s1[i + 1] == s2[i + 1] == '0':
                    ans += 2
                    skip = True
        elif s1[i] == s2[i] == '0':
            if i + 1 <= n - 1:
                if s1[i + 1] == s2[i + 1] == '1':
                    ans += 2
                    skip = True
                else:
                    ans += 1
            else:
                ans += 1
    print(ans)
