A,B,C,K=map(int,input().split())
print(min(A,K)-max(min(C,K-A-B),0))