n, x, y = map(int, input().split())
s = input()
c = len([_ for _ in s.split("1") if _])
ans = 1e9
if not c:
    ans = 0

for i in range(c):
    ans = min(ans, i*x + (c-i)*y)
print(ans)
