N,M,K = map(int,input().split())
ans = 'No'
for n in range(N):
    for m in range(M):
        tmp = ((N-n)*m + (M-m)*n)
        if tmp==K:
            ans = 'Yes'
print(ans)