t=int(input())
for i in range(t):
    l=[]
    f=0
    n=int(input())
    a=[int(i) for i in input().split()]
    
    temp=a[0]
    l.append(temp)
    
    if(a[0]<a[1]):
        f=0
    else:
        f=1
    for j in range(n-1):
       if(temp<a[j+1]):
           if(f==0):
            temp=a[j+1]
           else:
            f=1
            l.append(a[j])
            temp=a[j+1]
       else:
           if(f==1):
            temp=a[j+1]
           else:
            f=0
            l.append(a[j])
            temp=a[j+1]
    
    l.append(temp)
            
    print(len(l),end='\n')
    for i in l:
        print(i,end=' ')
    print(end='\n')