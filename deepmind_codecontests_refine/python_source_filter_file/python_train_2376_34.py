h,w=map(int,input().split())
l=[list(map(int,input().split())) for _ in range(h)]
ans=[]
cnt=0
for i in range(h):
    for j in range(w-1):
        if l[i][j]%2==1:
            l[i][j]-=1
            l[i][j+1]+=1
            cnt+=1
            ans.append([i+1,j+1,i+1,j+2])
print(l)
for i in range(h-1):
    if l[i][w-1]%2==1:
        l[i][w-1]-=1
        l[i+1][w-1]+=1
        cnt+=1
        ans.append([i+1,w,i+2,w])
print(cnt)
for i in ans:
    print(*i)