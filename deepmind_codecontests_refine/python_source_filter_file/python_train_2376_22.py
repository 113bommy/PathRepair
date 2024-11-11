h,w=map(int,input().split())
a=[list(map(int,list(input().split()))) for _ in range(h)]

ans=[]
for i in range(h):
    for j in range(w-1):
        if a[i][j]%2==1:
            a[i][j+1]+=1
            ans.append([i+1,j+1,i+1,j+2])

for i in range(h-1):
    if a[i][-1]%2==1:
        a[i+1][-1]+=1
        ans.append([i+1,j+1,i+2,j+1])

print(len(ans))
for i in ans:
    print(*i)