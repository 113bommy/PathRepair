n = int(input())
a = list(map(int, input().split()))
b = sorted(a, reverse=True)
ans = 0
for i in range(n):
    ans += b[(i+1)//2]
print(ans)
