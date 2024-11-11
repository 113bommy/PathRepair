s=input()
if '.' in s:
    if s[0]=='-':
        i=1
        a='$'
        while s[i]!='.':
            a=a+s[i]
            i=i+1
        c=0
        x=len(a)
        d=''
        for j in range(x-1,0,-1):
            c=c+1
            d=a[j]+d
            if c==3 and j!=1:
                d=','+d
                c=0
        a='$'+d
        a=a+'.'
        f=s[i+1:i+3]
        f=f+'00'
        a=a+f[0:2]
        print('('+a+')')
    else:
        i=0
        a='$'
        while s[i]!='.':
            a=a+s[i]
            i=i+1
        c=0
        x=len(a)
        d=''
        for j in range(x-1,0,-1):
            c=c+1
            d=a[j]+d
            if c==3 and j!=1:
                d=','+d
                c=0
        a='$'+d
        a=a+'.'
        f=s[i+1:i+3]
        f=f+'00'
        a=a+f[0:2]
        print(a)
        
else:
    b=0
    if s[0]==-1:
        b=1
    a='$'+s[1:]
    c=0
    x=len(a)
    d=''
    for i in range(x-1,0,-1):
        c=c+1
        d=a[i]+d
        if c==3 and i!=1:
            d=','+d
            c=0
    a='$'+d
    a=a+'.00'
    
    if b:
        print('('+a+')')
    else:
        print(a)