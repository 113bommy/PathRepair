N,M = map(int,input().split())
if N > M//2:
    print(0)
    exit()
ans = (M//2 - N)//2 + N
print(ans)