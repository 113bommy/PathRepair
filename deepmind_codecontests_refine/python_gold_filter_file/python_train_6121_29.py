N = int(input())
l = list(map(int, input().split()))
ans = [0]*N

for i in range(N):
    ans[l[i]-1] = i+1
print(*ans)