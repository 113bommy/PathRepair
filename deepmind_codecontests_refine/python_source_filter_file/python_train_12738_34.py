n = int(input().strip())
if n == 1:
    print(-1)
else:
    ans = [i for i in range(1,n+1)]
    print(*ans)
