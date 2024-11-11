n = int(input())
a = list(map(int,input().split()))
s = sum(a)
ans = float("inf")
x = 0

for i in range(n-1):
    x += a[i]
    ans = min(ans,abs(s-2*x))

print(ans)
