# 2019/08/14

x,y=map(int,input().split())
ans=abs(abs(x)-abs(y))

if (x<0 and y<0) or (x>0 and y>0):
    if x>y :ans+=2
elif x!=0 and y!=0:
    ans+=1
else:
    if y<=0 and x>y:
        ans+=1

print(ans)