Q = int(input())
src = [tuple(map(int,input().split())) for i in range(Q)]
ans = []
for x,y,k in src:
    d = max(x,y)
    if (x+y)%2:
        ans.append(-1 if d > k else k-1)
    else:
        if d > k:
            ans.append(-1)
        else:
            ans.append(k-2 if (d+k)%2 else k)

print(*ans,sep='\n')
