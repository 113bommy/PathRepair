t = int(input())
for _ in range(t):
    n = int(input())
    s = str(input())
    ans = ''
    for i in range(n):
        ans += s[i:n+i][0]
    print(ans)