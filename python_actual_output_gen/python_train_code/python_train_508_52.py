n,x=map(int,input().split())
m = [int(input()) for _ in range(n)]
print(n+((n-sum(m))//min(m)))