n,c = map(int,input().split())
l = [[0]*(10**5+1) for _ in range(c+1)]
for _ in range(n):
    s,t,c = map(int,input().split())
    for i in range(s,t+1):
        l[c-1][i] = 1
ans = [0]*10**5
for i in range(len(l)):
    for j in range(len(l[i])):
        ans[j] += l[i][j]
print(max(ans))