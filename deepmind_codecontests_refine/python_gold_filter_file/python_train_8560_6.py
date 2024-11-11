n=int(input())

for i in range(n):
    
    t,v,l=(map(int,input().split()))
    
    def L(h):
        return h-10
    def V(h):
        return h//2 + 10 
    cv=0
    cl=0
    while(cv<v and cl <l):
        if(t/2<=10):
            t = L(t)
            cl=cl+1
#            print(t)
        else:
            t = V(t)
            cv=cv+1
#            print(t)
    if(t>0 and cl<l):
        while(cl<l):
            t = L(t)
            cl=cl+1
#            print(t)
    if(t>0 and cv<v):
        while(cv<v):
            t = V(t)
            cv=cv+1
#            print(t)
            
    if(t>0):
        print("no")
    else:
        print("yes")
        