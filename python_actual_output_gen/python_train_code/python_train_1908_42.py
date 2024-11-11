N,M,K=map(int,input().split())
for k in range(1,N+1):
    for l in range(1,M+1):
        tmp=(M-l)*k+(N-k)*l
        if tmp==K:
            print("Yes")
            exit()

print("No")