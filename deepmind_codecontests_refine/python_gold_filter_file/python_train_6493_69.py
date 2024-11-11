n = int(input())
ans = 0
for i in range(n):
    ans += i*(n-i)
ans += n
print(ans)