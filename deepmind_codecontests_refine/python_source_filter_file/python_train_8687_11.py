n, m, k = map(int, input().split())
a = [int(input()) for __ in range(m)]
x = int(input())
ans = 0
for y in a:
    if bin(x ^ y).count('1') <= 1:
        ans += 1
print(ans)