n, m, k = map(int, input().split())

x = [int(input()) for i in range(m)]

F = int(input())

ans = 0
for el in x:
    if bin(el ^ F).count('1') <= k:
        ans += 1

print(ans)