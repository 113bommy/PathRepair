a,b=map(int,input().split())
if a>b: a,b=b,a
ans=2
for i in range(3,a+1):
    ans*=i
print(ans)