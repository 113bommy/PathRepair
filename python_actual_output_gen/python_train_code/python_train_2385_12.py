for i in range(int(input())):
    a=input()
    c,f,ans=0,0,0
    l=[]
    for i in a:
        if f==0 and i=='1':
            f=1
        elif f==1 and i=='0':
            l.append(c)
            c=0
            f=0
        if f:
            c+=1
            
    if c!=0:l.append(c)
    l.sort(reverse=1)
    j=0
    while j<len(l):
        if j%2==0:
            ans+=l[j]
        j+=1
    print(l)
        
        
        
    
