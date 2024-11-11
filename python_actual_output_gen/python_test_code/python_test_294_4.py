t = int(input())
for _ in range(t):
    s = str(input())
    n  = len(s)
    ans = 0
    for i in range(n):
        if s[i] == '0':
            if i == 0 or i == n-1:
                continue
            p = s[0:i+1]
            q = s[i+1:-1]
            if '1' in p and '1' in q:
                ans += 1
    print(ans)