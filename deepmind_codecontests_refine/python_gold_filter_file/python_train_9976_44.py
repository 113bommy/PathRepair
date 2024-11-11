X = int(input())

ans = 1
for b in range(2, X):
    x = b * b
    while x <= X:
        ans = max(ans, x)
        x *= b
print(ans)
