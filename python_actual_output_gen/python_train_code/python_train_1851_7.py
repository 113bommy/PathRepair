a=str(input())
b=str(input())
d=''
flag=0
if(len(a)<=len(b)):
    for i in range(0,len(a)):
        if(a[i]!=b[i]):
            if(len(d)<4):
                d=d+a[i]+b[i]
            else:
                flag=1
                break
    if(len(set(d))==2 and len(d)==4 and flag==0):
        print('YES')
    else:
        print("NO")
else:
    print("NO")

    