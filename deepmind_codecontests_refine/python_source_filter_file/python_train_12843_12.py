n,m = map(int,input().split())
l = list(map(int,input().split()))
ans,k = 0,0
for i in l:
    k = 0
    for j in str(i):
        if j == "4" or j == "7":
            k += 1
    if k < m:
        ans += 1
print(ans)