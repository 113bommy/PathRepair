n, p = map(int, input().split())
s = list(map(int, list(input())))
if p == 2 or p == 5:
    ans = 0
    for i in range(n):
        if s[i] % p == 0:
            ans += i + 1
    print(ans)
else:
    lis = [0] * p
    cnt = 0
    kurai = 1
    for i in s[::-1]:
        cnt += i * kurai % p
        cnt %= p
        lis[cnt] += 1
        kurai *= 10
        kurai %= p
    ans = 0
    for i in lis:
        ans += i * (i - 1) // 2
    ans += lis[0]
    print(ans)