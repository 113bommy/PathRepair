MOD = 1000000007

for _ in range(int(input())):
    n, k = map(int, input().split())
    ans = 0.
    for digit in bin(k):
        ans *= n
        if digit == '1':
            ans += 1
        ans %= MOD
    print(ans)
