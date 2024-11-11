N,M,K=map(int,input().split())
a=0
for i in range(N+1):
    for j in range(M+1):
        if i*M+j*N-2*i*j==K:
            a=1
print(["No","Yes"][a])
