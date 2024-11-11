n = int(input())
ans = set(list(map(int, input().split())))
for i in range(1, n):
    y = set(list(map(int, input().split())))
    ans = ans & y
print(*ans)
