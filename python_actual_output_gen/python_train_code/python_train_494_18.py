n,k=map(int,input().split())
a=list(map(int,input().split()))
c=[]
b=sorted(a)
if k>=b[0]:
    for i in range(n-1):
        if k<=0:
            break
        elif (k-b[i])>=b[i+1] :
            c.append(a.index(b[i])+1)
            k=k-b[i]
            a[a.index(b[i])]=101
        elif ((k-b[i])<b[i+1]):
            for j in range(i,n-1):
                if k-b[j]>=0:
                    c.append(a.index(b[j])+1)
                    k=k-b[j]
                    a[a.index(b[j])]=101    
                    
                
    #print(k)
    if k>0:
        if k-b[n-1]>0:
            c.append(a.index(b[n-1])+1)
    print(len(c))
    print(*c)
else:
    print(0)
    
    
    
        
        