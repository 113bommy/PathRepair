n=int(input())

max=0
for i in range(n):
    a,b=map(int,input().split())
    if a>max: ans=a+b

print(ans)