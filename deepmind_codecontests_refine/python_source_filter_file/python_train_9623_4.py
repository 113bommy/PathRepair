n = int(input())
a = [*map(int, input().split())]
xor_sum = [0]*(n+1)

ans = 0
for x in a:
    ans ^= x

for i in range(1, n+1):
    xor_sum[i] = xor_sum[i-1] ^ i

for i in range(1, n+1):
    x = n // i
    y = n % i
    if x % 2:
        ans ^= xor_sum[i-1]^xor_sum[y]
    else:
        ans ^= xor_sum[y-1]

print(ans)