x,y=map(int,input().split())
ans=0
if x<=3:
    ans+=(4-x)*100000
if y<=3:
    ans+=(4-x)*100000
if ans==600000:
    ans=1000000
print(ans)