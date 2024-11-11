K,T=map(int,input().split())
A=list(map(int,input().split()))
M=max(A)
print(max(M-1-(K-M),0))