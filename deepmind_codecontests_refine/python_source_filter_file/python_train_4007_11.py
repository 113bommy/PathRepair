n,m,k=map(int,input().split())
A=[]
for i in range(n):
    A.append([0]*m)
dic=[[1,0],[1,-1],[-1,0],[-1,-1],[-1,0],[-1,1],[0,1],[1,1],[1,0]]
C=[]
T=0
for item in range(k):
    C.append(list(map(int,input().split())))

for u in C:
    T+=1
    i,j=u[0]-1,u[1]-1
    A[i][j]=1
    for d in range(3):
        if i+dic[d][0]>=n or i+dic[d][0]<0 or j+dic[d][1]>=m or j+dic[d][1]<0:
            break
        else:
            if A[i+dic[d][0]][j+dic[d][1]]==0:
                break
    else:
        print(T)
        break
    for d in range(2,5):
        if i+dic[d][0]>=n or i+dic[d][0]<0 or j+dic[d][1]>=m or j+dic[d][1]<0:
            break
        else:
            if A[i+dic[d][0]][j+dic[d][1]]==0:
                break
    else:
        print(T)
        break
    for d in range(4,7):
        if i+dic[d][0]>=n or i+dic[d][0]<0 or j+dic[d][1]>=m or j+dic[d][1]<0:
            break
        else:
            if A[i+dic[d][0]][j+dic[d][1]]==0:
                break
    else:
        print(T)
        break
    for d in range(6,9):
        if i+dic[d][0]>=n or i+dic[d][0]<0 or j+dic[d][1]>=m or j+dic[d][1]<0:
            break
        else:
            if A[i+dic[d][0]][j+dic[d][1]]==0:
                break
    else:
        print(T)
        break
else:
    print(0)
        
