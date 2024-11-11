n=int(input())
c1=0;c2=0;
for i in range(n):
    [x,y]=list(map(int,input().split()));
    if(x>0):c1+=1;
    else:c2+=1;
    
    if(c1>1 and c2>1):break;
if(c1==1 or c2==1):print("yes");
else:print("no")
