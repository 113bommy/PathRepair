N,M,K = list(map(int,input().split()))
for i in range(0,N+1):
    for j in range(0,M+1):
        if (N-i)*j+(M-j)*i == K:
            print('Yes')
            exit()
print('No')