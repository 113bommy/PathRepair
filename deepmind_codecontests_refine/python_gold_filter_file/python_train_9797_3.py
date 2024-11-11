n, b = map(int, input().split())
ans = (n + b * 2)  // (b * 2 + 1)
a = []
for i in range(ans):
    a.append((b + 1) + (b * 2 + 1) * i)
while a[-1] > n:
    for i in range(ans):
        a[i] -= 1
print(ans)
print(" ".join(map(str, a)))