x,y = map(int,input().split())
ans = 10000000000
for a,b,c in [(x,y,0),(x,-y,1),(-x,y,1),(-x,-y,2)]:
    if a <= b:
        ans = min(ans,b-a+c)
print(ans)