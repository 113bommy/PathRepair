n = int(input())
a = [*map(int, input().split())]
ans = 0
current = 1
for i in range(n):
    if a[i] >= a[i - 1]:
        current += 1
    else:
        if current > ans:
            ans = current
        current = 1
print(max(ans, current))
