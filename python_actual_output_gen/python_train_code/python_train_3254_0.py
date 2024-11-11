s = input()
d,lst = {},[]
for i,x in enumerate(s):
    if d.get(x)==None:
        d[x]=0
        lst.append(x)
    d[x]+=1
le = len(d)
if le==1 or le>4:
    print('No')
else:
    if le==2:
        if d[lst[0]]>1 and d[lst[1]]>1:
            print('Yes')
        else:
            print('No')
    elif le==3:
        if len(s)>1:
            print('Yes')
        else:
            print('No')
    else:
        print('Yes')