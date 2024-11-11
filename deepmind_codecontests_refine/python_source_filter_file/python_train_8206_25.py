n = int(input())
a = list(map(int,input().split()))
x = 0
y = sum(a)
ans = 10 ** 9
for i in range(n-1):
    x += a[i]
    y -= a[i]
    ans = min(ans,abs(x-y))
print(ans)