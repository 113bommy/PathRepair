n=int(input())
B=list(map(int,input().split()))
k=0
A=[0]*n
i=0
k+=abs(B[0]-A[0])
for i in range(1,n-1):
    k+=abs(B[i+1]-B[i])
print(k)
