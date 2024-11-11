h,w=map(int,input().split())
cnt=0
ans=[]
a=[list(map(int,input().split())) for _ in [0]*h]
for i in range(h):
    for j in range(w-1):
        if a[i][j]%2:
            a[i][j+1]+=1
            cnt+=1
            ans.append((i+1,j+1,i+2,j+2))
for i in range(h-1):
    if a[i][w-1]%2:
        a[i+1][w-1]+=1
        ans.append([i+1,w,i+2,w])
        cnt+=1
print(cnt)
for i in ans:
    print(*i)