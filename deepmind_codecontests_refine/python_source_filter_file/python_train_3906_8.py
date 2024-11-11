n , m = map(int,input().split())
ans=0
for i in range(n):
    a , b = map(int,input().split())
    ans = max(ans,a+b)
print(ans)    