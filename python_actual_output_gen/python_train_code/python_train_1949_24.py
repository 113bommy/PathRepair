a, b = map(int, input().split())
ans = 0
if a * b < 0:
    ans += 1
elif (a > 0 and b > 0) or (a == 0 and b < 0):
    ans += 1
elif b < a:
    ans += 2

ans += abs(abs(a) - abs(b))
print(ans)