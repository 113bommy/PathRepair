H,W=map(int,input().split())
S=[[i=="." for i in input()+"#"] for _ in range(H)]+[[False]*(W+1)]

map_=[[0]*W for _ in range(H)]
for i in range(H):
    cnt=0
    q=[]
    for j in range(W+1):
        if S[i][j]==False and cnt!=0:
            for Q in q:
                map_[Q[0]][Q[1]]=cnt
            cnt=0
            q=[]
        elif S[i][j]:
            cnt+=1
            q.append([i,j])
for j in range(W):
    cnt=0
    q=[]
    for i in range(H+1):
        if S[i][j]==False and cnt!=0:
            for Q in q:
                map_[Q[0]][Q[1]]+=cnt
            cnt=0
            q=[]
        elif S[i][j]:
            cnt+=1
            q.append([i,j])
print(max([max(i) for i in map_])-1)
