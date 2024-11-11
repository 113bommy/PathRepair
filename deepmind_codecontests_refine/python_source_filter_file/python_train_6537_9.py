N=int(input())
B=list(map(int,input().split()))
B.append(10000)
A=0

for i in range(0,N):
    A+=min(B[i],B[i-1])
    
print(A)