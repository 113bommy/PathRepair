t=int(input())
while t>0:
    t-=1
    c=0
    n,m=map(int,input().split())
    l=[]
    for i in range(n):
        
        
        p=list(map(int,input().split()))
        if 1 not in p:
            c+=1
        l.append(p)
    flag=0
    if c==0:
        print("Vivek")
    else:
        for i in range(m):
            k=0
            for j in range(n):
                if l[j][i]==1:
                    k=1
                    break
            if k==0:
                flag+=1
        #print("col=",flag,"row=",c)
        if flag==c:
            if c%2==0:
                print("Vivek")
            else:
                print("Ashish")
        else:
            
            a=abs(flag-c)
            if a%2==0:
                print("Vivek")
            else:
                print("Ashish")
        
            
                
    
      
   
