N,M,K=map(int,input().split())

for i in range(N+1):
    for j in range(M+1):
        if(K==(i*(M-j)+j*(N-i))):
            print("Yes")
            exit()

print("No")