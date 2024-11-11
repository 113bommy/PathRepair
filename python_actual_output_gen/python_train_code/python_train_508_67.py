N,X=map(int,input().split())
M=[input() for i in range(N)]
print((X-sum(M))//min(M)+N)