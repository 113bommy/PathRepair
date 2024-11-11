n,s = map(int, input().split())
ans = 0
for i in range(n):
    x,y = map(int,input().split())
    ans = max(ans,x+y)
print(ans)