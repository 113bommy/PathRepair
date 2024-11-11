a,b,c=map(int,input().split())
k=int(input())
m=max(a,b,c)
print(m*(1<<k)+a+b+c-m)