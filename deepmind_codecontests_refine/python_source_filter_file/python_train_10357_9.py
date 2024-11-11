l=list(map(int,input()))
s=['','one','two','three','four','five','six','seven','eight','nine']
f=['','ten','twenty','thirty','fourty','fifty','sixty','seventy','eighty','ninety']
t=['','eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen']
if len(l)>1:
    if l[0]!=1 and l[1]!=0:
       l[0]=f[l[0]]
       l[1]=s[l[1]]
       print('-'.join(l))
    elif l[0]!=1 and l[1]==0:
        print(f[l[0]])
    else:
        if l[1]==0: print(f[1])
        else: print(t[l[1]])
else: print(s[l[0]])