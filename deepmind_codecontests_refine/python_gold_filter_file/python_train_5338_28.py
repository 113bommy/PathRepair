#t=int(input())
t=1
for _ in range(t):
    n=int(input())
    
    z=input().split()
    
    
    w=[]
    for i in range(n):
        z[i]=int(z[i])
    if n==2:
        print(0)
        print(z[0],z[1])
    else:  
        z.sort()
        for i in range(n):
            w.append(z[i])
        for i in range(1,n-1,2):
            z[i],z[i+1]=z[i+1],z[i]
        for i in range(0,n-1,2):
            w[i],w[i+1]=w[i+1],w[i]
        a1=0
        a2=0
        for i in range(1,n-1):
            if w[i]<w[i+1] and w[i]<w[i-1]:
                a1+=1

            if z[i]<z[i+1] and z[i]<z[i-1]:
                a2+=1
        if a1>=a2:
            print(a1)
            for i in range(n):
                print(w[i],end=" ")
            print()
        else:
            print(a2)
            for i in range(n):
                print(z[i],end=" ")
            print()
        
                
        
        