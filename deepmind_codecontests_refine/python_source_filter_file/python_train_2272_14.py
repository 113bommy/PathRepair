import itertools

N,C=map(int,input().split())
D=[[] for _ in range(C)]
c=[[] for _ in range(N)]

for i in range(C):
    D[i]=list(map(int,input().split()))
    
for i in range(N):
    c[i]=list(map(int,input().split()))
    
hist=[[0]*3 for i in range(C)]#hist[i][j]は余りiのマスにj色のマスがいくつあるか
    
    
for i in range(N):
    for j in range(N):
        rem=(i+j+2)%3
        hist[rem][c[i][j]-1]+=1
    
ans=10**10
for cset in itertools.permutations(range(C), 3):
    temp=0
    for i in range(3):
        for j in range(C):
            temp+=hist[i][j]*D[j][cset[i]]
    ans=min(ans,temp)
    
print(ans)
    