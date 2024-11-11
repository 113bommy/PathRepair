A,B,K=map(int,input().split())
X=min(A,K)

A-=X
K-=X
B-=K

print(A,B)