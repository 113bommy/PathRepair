h,w = map(int,input().split())
ma = [list(map(int,input().split())) for _ in range(10)]
for i in range(10):
    for j in range(10):
        for k in range(10):
            ma[i][j] = min(ma[i][j], ma[i][k]+ma[k][j])
li = [list(map(int,input().split())) for _ in range(h)]
ans = 0
for each_li in li:
    for l in each_li:
        if l!=-1:
            ans += ma[l][1]
print(ans)