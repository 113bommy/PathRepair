n = int(input().strip())
if n == 1:
    print(-1)
else:
    ans = [i for i in range(n,0,-1)]
    print(*ans)
