n = int(input())
a = list(map(int, input().split()))
ans = 10*10
for x in range(1, n+1):
    l = 0
    for i in range(1, n+1):
        l += 2*a[i-1]*(abs(x-i)+abs(i-1)+abs(x-1))
    ans = min(ans, l)
print(ans)