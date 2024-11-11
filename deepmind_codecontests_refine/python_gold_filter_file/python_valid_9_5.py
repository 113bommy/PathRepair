for i in range(int(input())):
    
    
    s=input()
    n=len(s)
    r=set()
    g=set()
    
    i=0
    d={}
    for i in s:
        d[i]=d.get(i,0)+1
    r=0
    g=0
    for i in d.keys():
        if d[i]>1:
            r+=1
            g+=1
        else:
            if r>g:
                g+=1
            else:
                r+=1
    print(min(g,r))