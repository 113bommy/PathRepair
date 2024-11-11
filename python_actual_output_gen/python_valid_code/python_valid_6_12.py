n,k=map(int,input().split())
A=[]
for _ in range(n):
    A.append(list(map(int,input().split())))
cnt=A[0][1]
i=0
while cnt<k:
    i+=1
    cnt+=A[i][1]
print(A[i][0])