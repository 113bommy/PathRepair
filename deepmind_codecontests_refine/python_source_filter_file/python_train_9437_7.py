a = input()
b = set()
for i in a:
    b.add(i)
l = len(b)
if l==2:
    b = {}
    l = 0
    for i in a:
        if i in b:
            b[i]+=1
        else:
            b[i]=1
    for i in b:
        if b[i]>1:
            l=l+1
    if l==2:
        print("YES")
    else:
        print("NO")
elif l>=3 and l<=4:
    if l==4:
        print("YES")
    else:
        b = {}
        for i in a:
            if i in b:
                b[i]+=1
            else:
                b[i]=1
        l = 0
        for i in b:
            if b[i]>1:
                l=l+1
        if l>=2:
            print("YES")
        else:
            print("NO")
else:
    print("NO")
