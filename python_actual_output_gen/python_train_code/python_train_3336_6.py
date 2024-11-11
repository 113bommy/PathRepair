N=int(input())
H=list(map(int,input().split(' ')))
ans = 0
for i in range(N-1):
    ans += max(0,H[i+1]-H[i])
print(ans)