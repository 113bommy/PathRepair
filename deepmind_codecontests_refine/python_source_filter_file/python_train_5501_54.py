N,M,K = list(map(int,input().split()))
for i in range(1,N+1):
    for j in range(1,M+1):
        if (N-i)*j+(M-j)*i == K:
            print('Yes')
            exit()
print('No')