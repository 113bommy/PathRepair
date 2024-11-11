n= int(input())
l=[]
for i in range(n):
    x=0
    ch=True
    l.append(input())
    if l[i][0]=='R' and len(l[i])>3 and ord(l[i][1])<58:
        for x in range(2,len(l[i])):
            if ord(l[i][x])>57:
                ch=False
                break
    x=0
    s=0
    t=''
    p=''
    if ch:
        while ord(l[i][x])>57:
            s=26*s+ord(l[i][x])-64
            x+=1
        l[i]=f'R{l[i][x:]}C{s}'
    else:
        x=1
        while l[i][x]!='C':
            t+=l[i][x]
            x+=1
        x+=1
        s=int(l[i][x:])
        while s>0:
            if s%26==0:
                p+=chr(90)
                s-26
            else:
                p+=chr((s%26)+64)
            s=s//26
        l[i]=p[::-1]+t
for i in l:
    print(i)
