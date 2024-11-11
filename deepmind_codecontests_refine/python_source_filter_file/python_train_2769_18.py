a, b = map(int, input().split())
ans = 1
for i in range(1, min(a, b)):
    ans *= i

print(ans)