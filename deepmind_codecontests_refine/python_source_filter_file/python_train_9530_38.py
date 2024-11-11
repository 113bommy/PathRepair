n=int(input())
ans=0
for i in range(n):
    x,y,z=map(str,input().split())
    if int(y)>2400 and int(z)>2400 and int(z)>int(y):
        ans+=1
if ans>0:
    print("YES")
else:
    print("NO")