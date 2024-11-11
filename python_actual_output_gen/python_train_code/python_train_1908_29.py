N,M,K=map(int,input().split())
flag=False
for n in range(N):
    for m in range(M):
        if (N-n)*m+(M-m)*n==K:
            flag=True
print("Yes" if flag else "No")