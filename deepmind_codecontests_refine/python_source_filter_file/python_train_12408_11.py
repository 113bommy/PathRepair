R=lambda:map(int,input().split());n,m=R();flag=0;
while(flag!=1 or n<=m):
    new=str(n)
    old=set(new)
    if(len(old)==len(new)):
        flag=1
        break
    else:
        n+=1
    if n>=m:
        break
if flag==1:
    print(n)
else:
    print(-1)