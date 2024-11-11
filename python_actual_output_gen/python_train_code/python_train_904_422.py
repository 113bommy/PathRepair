a, b = map(int, input().split())
ans = a - 1
if b >= a:
    ans += 1
print(ans + 1)