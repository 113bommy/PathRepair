a, b = map(int, input().split(" "))
if a > b:
    a, b = b, a
ans = 1
for i in (2, a):
    ans *= i
print(ans)
