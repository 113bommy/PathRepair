N,K=map(int,input().split())
A=list(map(int,input().split()))

for i in range(K+1):
    if A[i+K]>A[i]:
        print('Yes')
    else:
        print('No')