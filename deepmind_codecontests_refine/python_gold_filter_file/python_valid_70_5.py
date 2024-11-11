for _ in range(int(input())):
    t=input()
    a=t[-1]
    b=a
    f=s=0
    hi=[]
    for i in range(len(t)-1,-1,-1):
        if(t[i]!=a):
            a=t[i]
            if(a not in b):
                b=b+a
    l=len(b)
    for ele in b:
        h=t.count(ele)
        if(h%l==0):
            h=h//l 
            s=s+h 
            hi.append(h)
            l=l-1 
        else:
            f=1 
            break
    if(f==1):
        print(-1)
    else:
        x1=x=t[:s]
        b=b[::-1]
        s1=s
        s2=s
        for i in range(len(b)):
            x=x.replace(b[i],"")
            s1=s1-hi[len(b)-1-i]
            s2=s1+s2
            if(x!=t[s:s2]):
                f=1 
                break 
            s=s2
        if(f==1):
            print(-1)
        else:
            print(x1,b)
        
            
    