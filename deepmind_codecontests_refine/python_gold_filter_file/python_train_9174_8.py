n,m,k =map(int,input().split())
A=list(map(int,input().split()))
B=[]
for i in range(1,n):
    B.append(A[i]-A[i-1])
B.sort()
s=k
for i in range(n-k):
    s+=B[i]
print(s)    
