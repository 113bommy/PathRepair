N = int(input())
a = list(map(int,input().split()))

s = sum(a)
l = 0

ans = 10**9
   
for i in range(N-1):
    l += a[i]
    ans = min(ans, abs(s - 2*l))

print(ans)