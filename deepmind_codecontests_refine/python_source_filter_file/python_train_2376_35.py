h,w=map(int,input().split())
A=[list(map(int,input().split())) for _ in range(h)]

B=[]
for i in range(h):
    flag=1 if i%2==0 else -1
    for j in range(w)[::flag]:
        if A[i][j]%2==1:
            if 0<=j+flag<w:
                B.append([i,j,i,j+flag])
                A[i][j+flag] +=1
            else:
                B.append([i,j,i+1,j])
                A[i+1][j] +=1

print(len(B))
for i in B:
    print(*list(map(lambda x:x+1,i)))