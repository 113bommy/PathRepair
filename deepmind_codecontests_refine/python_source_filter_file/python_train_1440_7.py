n,x,m = map(int,input().split()),[int(input()) for i in range(n)]
print(n+(x-sum(m))//min(m))