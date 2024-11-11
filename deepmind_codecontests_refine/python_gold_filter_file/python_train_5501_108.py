N,M,k=map(int,input().split())
for i in range(N+1):
    for j in range(M+1):
        tmp=N*j+M*i-2*i*j
        if tmp==k:
            print("Yes")
            exit()
print("No")