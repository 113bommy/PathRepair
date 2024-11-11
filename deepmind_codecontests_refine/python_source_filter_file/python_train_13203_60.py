from sys import exit


n = int(input())

ans = 0
for q in range(n):
    limit, x, y = map(int, input().split())
    if limit < (x + y) or (limit + x + y) % 2:
        print("NO")
        exit(0)


print("YES")