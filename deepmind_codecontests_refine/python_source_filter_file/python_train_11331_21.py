K = int(input())
n = 50

ans = [n-1+n*(K//n)-(K-K//n)]*(n-K%n) + [n-1+n*(K//n+1)-(K-K//n+1)]*(K%n)
print(n)
print(*ans)