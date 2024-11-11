n,m=map(int,input().split())
A=list(map(int,input().split()))
BC=[list(map(int,input().split())) for _ in range(m)]
A.sort()
BC.sort(key=lambda x:-x[1])

B=[]
for bc in BC:
    B+=[bc[1]]*bc[0]
    if len(B)>=N:
        break
B+=[0]*(N-len(B))
print(sum([max(A[i],B[i]) for i in range(N)]))
