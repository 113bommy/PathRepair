h,w=map(int,input().split())
A=[]
for i in range(h):
    A.append(list(map(int,input().split())))
    
S=[]
for i in range(h):
    for j in range(w-1):
        if A[i][j]%2!=0:
            A[i][j]-=1
            A[i][j+1]+=1
            S.append([i+1,j+1,i+1,j+2])
for i in range(h-1):
    if A[i][-1]%2!=0:
        A[i][-1]-=1
        A[i+1][-1]+=1
        S.append([i+1,w+1,i+2,w+1])
print(len(S))
for s in S:
    print(*s)