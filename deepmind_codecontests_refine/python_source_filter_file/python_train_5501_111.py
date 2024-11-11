N,M,K=map(int,input().split())
a=0
for i in range(1,N+1):
    for j in range(1,M+1):
        if i*M+j*N-2*i*j==K:
            a=1
print(["No","Yes"][a])