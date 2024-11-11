n=int(input())
a=list(input())
x=0
flag=0
for i in range(n):
    if a[i]=="(":
        x+=1
    else:
        if x>-1:
            x-=1
        else:
            flag=1
            break
if flag==1 or x>0:
    print("No")
else:
    print("Yes")