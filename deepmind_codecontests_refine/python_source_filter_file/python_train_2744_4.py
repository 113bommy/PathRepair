l=[]
ans=[[0 for i in range(60)]for j in range(25)]
c=0
n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    ans[a][b]+=1
for i in range(1,25):
    for j in range(1,60):
        if ans[i][j]>c:
            c=ans[i][j]
print(c)            
