N,M,K=map(int,input().split())
for i in range(N+1):
    for j in range(M+1):
        if (N-j)*i+(M-i)*j==K:
            print("Yes")
            exit()
else:
    print("No")