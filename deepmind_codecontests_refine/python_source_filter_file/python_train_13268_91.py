n = int(input())
ans = 0
for i in range(n):
    p, q = map(int, input().split())
    if q - 2 > p:
        ans += 1
    else:
        continue
print(ans)