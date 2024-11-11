N, M = map(int, input().split())
ans = int((M+2*N)/4)
if ans < N:
    print(N)
else:
    print(ans)


