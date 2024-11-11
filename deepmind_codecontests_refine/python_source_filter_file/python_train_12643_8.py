x, y = map(int, input().split())
N = int(input())
MOD = int(1e9) + 7
m = (N - 1) % 3
if m == 0:
    ans = x
elif m == 1:
    ans = y
elif m == 2:
    ans = y - x
mm = (N - 1) % 6
if mm >= 3:
    ans -= ans
ans %= MOD
print(ans)
