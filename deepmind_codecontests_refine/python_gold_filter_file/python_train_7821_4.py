n = int(input())
a = list(map(int, input().split()))
ans = 0
m = 2*10**9
for i in range(len(a)-1, -1, -1):
    m = min(a[i], m-1) if m > 0 else 0
    ans += m
    #print(m,ans)
print(ans)