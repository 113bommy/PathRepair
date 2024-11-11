n,x=map(int,input().split())
m=[int(input()) for _ in range(n)]
s=x-sum(m)
print(m+s//min(m))