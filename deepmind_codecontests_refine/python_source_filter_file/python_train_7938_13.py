def chess(a):
    n=a[0]
    m=a[1]
    x=a[2]
    y=a[3]
    c1=0
    i1=1
    while c1!=m:
        print(x,y)
        c1+=1
        if c1==m:
            break
        if y+i1<=m:
            y+=i1
        else:
            y=a[3]-1
            i1=-1
    if x+1<=m:
        x+=1
    else:
        x=1
    c=m
    i=-i1
    while c!=n*m:
        print(x,y)
        c+=1
        if y+i>m or y+i<1:
            if x+1<m:
                x+=1
                i=-i
            elif x+1>=m:
                x=1
                i=-i   
        else:
            y+=i
    return 

array=list(map(int,input().split(" ")))
chess(array)    