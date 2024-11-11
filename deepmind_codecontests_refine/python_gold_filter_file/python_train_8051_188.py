n = int(input())
part = 1 / n
a = list(map(int, input().split()))

ans = 0

for e in a:
    ans += part * e

print(ans)
