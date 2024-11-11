N,M,K=map(int,input().split())

for i in range(N):
    for j in range(M):
        if(K==(i*(M-j)+j*(N-i))):
            print("Yes")
            exit()

print("No")