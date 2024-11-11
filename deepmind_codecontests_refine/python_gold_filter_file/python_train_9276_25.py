n = int(input())
ans = set(list(map(int, input().split()))[1:])
for i in range(1, n):
    y = set(list(map(int, input().split()))[1:])
    ans = ans & y
print(*ans)
