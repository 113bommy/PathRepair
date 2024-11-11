N,K=map(int,input().split())
r=N%K
print(max(r,K-r))