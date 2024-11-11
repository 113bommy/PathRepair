N = int(input())
A = list(map(int, input().split()))

MOD = 10**9+7

sum_num = 0
for i in range(60):
    o = 0
    for a in A:
        o += (a>>i)%2
    z = N - o
    sum_num = (sum_num + (o*z)*(1<<i)) % MOD

print(sum_num)