N,M,K = [int(hoge) for hoge in input().split()]
ans = "No"
for n in range(N+1):
    for m in range(M+1):
        if m*(N-n) +n*(M-n)  == K:
            ans = "Yes"
print(ans)