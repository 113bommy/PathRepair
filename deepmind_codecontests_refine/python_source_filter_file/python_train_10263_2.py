

n = int(input())
v = [int(x) for x in input().split()]
mn = min(v)
mm = max(v)

ans = 0
for i in range(len(v)-1):
    if v[i] > mn and v[i] < mm:
        ans += 1
print(ans)
