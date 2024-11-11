x,y=map(int,input().split())
ans=0
if x<4:
    ans += x*100000
if y<4:
    ans += y*100000
if x==y and x==1:
    ans += 400000
print(ans)