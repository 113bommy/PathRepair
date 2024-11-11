n = int(input())
ans, a, b = "Yes", 0, 0
for i in range(n):
    x, y = map(int, input().split())
    if x < 0:
        a = a + 1
    else:
        b = b + 1
if a <= 1 or b <= 1:
    ans = "No"
print(ans)
