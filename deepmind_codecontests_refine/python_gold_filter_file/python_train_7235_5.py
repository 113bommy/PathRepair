n = int(input())
b = list(map(int, input().split()))

ans = abs(b[0])
for i in range(1, n):
    ans += abs(b[i] - b[i - 1])

print(ans)
