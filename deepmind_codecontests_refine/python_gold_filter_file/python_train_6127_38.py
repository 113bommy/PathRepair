N,M = map(int,input().split())
if N > M//2:
    print(M//2)
    exit()
ans = (M//2 + N)//2
print(ans)