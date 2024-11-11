N = int(input())
ans = 0
for i in range(1,N+1):
    if len(str(N))%2==1:
        ans += 1

print(ans)