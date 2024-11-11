N=int(input())
A=list(map(int,input().split()))
S=sum(A)
B=[0]*N
B[0]=S-2*sum(A[1::2])
for i in range(N-1):
    B[i+1]=2*A[i]-B[i]

print(*B)