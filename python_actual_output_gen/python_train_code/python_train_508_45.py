n,x=map(int,input().split())
m=[int(input()) for i in range(n)]
print(int((x-sum(m))/min(m))+3)