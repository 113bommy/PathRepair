N,M,K=map(int,input().split())
for i in range(N+1):
    for j in range(M+1):
        if (N-i)*j+(M-j)*i==K:
            print("Yes")
            exit()
else:
    print("No")