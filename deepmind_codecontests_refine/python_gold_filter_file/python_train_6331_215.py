n=int(input())
p=[int(input()) for i in range(n)]
ans=sum(p)-max(p)//2
print(ans)