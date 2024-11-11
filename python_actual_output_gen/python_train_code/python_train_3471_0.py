n=int(input())
p=map(int,input().split())
for i in range(1,n):p[i]=min(p[i-1],p[i])
print(len(set(p)))
