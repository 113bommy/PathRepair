n=int(input())
a=input()
bh=0
for i in a:
    if i=='(':
        bh=bh+1
    else:
        bh=bh-1
        if bh<-1:
            break
if bh>=0:
    print("Yes")
else:
    print("No")
