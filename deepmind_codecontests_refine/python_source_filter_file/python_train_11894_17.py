t = int(input())
for k in range(t):
    n = int(input())
    ans = []
    if n < 4:
        print(-1)
    else:
        for i in range(n - abs(n % 2 - 1), 0, -2):
            ans.append(i)
        ans += [4, 2]
        for i in range(6, n - (n % 2), 2):
            ans.append(i)
        print(' '.join(map(str, ans)))