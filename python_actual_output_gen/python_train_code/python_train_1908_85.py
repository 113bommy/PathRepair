N,M,K = map(int,input().split())
for n in range(N):
    for m in range(M):
        if n*m+(N-n)*(M-m) == K:
            print("Yes")
            exit()
print("No")