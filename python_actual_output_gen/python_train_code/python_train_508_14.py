n,x=map(int,input().split())
M=[int(input()) for _ in range(n)]
print(x-sum(M) + x//min(M))