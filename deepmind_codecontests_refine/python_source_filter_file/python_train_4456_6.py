N = int(input())
T = []
for i in range(N):
    A = int(input())
    for j in range(A):
        x,y = map(int,input().split())
        T.append([i,x-1,y==1])

ans = 0
for i in range(1<<N):
    h=[]
    for j in range(N):
        if(i&(1<<(j+1))):
            h.append(j)

    for j,x,y in T:
        if(j in h):
            if(not((x in h)==y)):
                break
    else:
        ans = max(ans,len(h))

print(ans)
            

