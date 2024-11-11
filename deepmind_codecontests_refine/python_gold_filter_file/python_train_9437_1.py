s=input()
if len(s)<4:
    print('No')
else:
    a={}
    for i in s:
        if i in a:
            a[i]+=1
        else:
            a[i]=1
    x=0
    for i in a:
        if a[i]>1:
            x+=1
    if (x>=2 or len(a)>2) and len(a)<5:
        print('Yes')
    else:
        print('No')
