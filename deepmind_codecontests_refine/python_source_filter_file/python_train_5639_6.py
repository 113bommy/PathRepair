n = int(input())
k = ans = 0
for i in range(4):
    a, b = map(int, input().split())
    k -= a
    k += b
    ans = max(ans, k)
print(ans)
