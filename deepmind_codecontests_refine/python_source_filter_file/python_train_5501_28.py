N,M,K = map(int,input().split())
for a in range(N+1):
    for b in range(N+1):
        k = a*b + (N-a)*(M-b)
        if k==K:
            print('Yes')
            exit()
print('No')