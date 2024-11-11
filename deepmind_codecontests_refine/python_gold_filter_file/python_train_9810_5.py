for _ in range(int(input())):
    n = int(input())
    s = input()
    mins = 'z'*(n+1)
    ans = -1
    for i in range(n):
        ts = ''
        if (n - i) % 2 == 0:
            ts = s[i:] + s[:i]
        else:
            ts = s[i:] + s[:i][::-1]
        if ts < mins:
            mins = ts
            ans = i + 1
    print(mins)
    print(ans)
