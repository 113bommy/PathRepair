for _ in range(int(input())):
    s = str(input())
    ans = str()
    for i in range(len(s)):
        if i % 2 == 0:
            ans += ('a' if s[i] == 'b' else 'b')
        else:
            ans += ('y' if s[i] == 'z' else 'z')
    print(ans)
