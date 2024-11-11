K,T=map(int,input().split())
A=list(map(int,input().split()))
M=max(A)
print(max(A-1-(K-A),0))