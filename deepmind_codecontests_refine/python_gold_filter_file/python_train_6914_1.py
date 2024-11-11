a=int(input())
l=input().split()


d={}
for i in range(a):
    d[i]=int(l[i])


def check(d):
    t=0
    for i in range(a):
        if d[i]!=0:
            t=1
            return False
        else:
            t=0
    if t==0:
        return True

p=""

for i in range(10000000):
    if check(d)==False:
        if i%2==0:
            for j in range(a):
                if i>0 and j==0:
                    p=p
                elif j==a-1:
                    if d[j]==0:
                        p=p+"L"
                        
                    elif d[j]>0:
                        p=p+"PL"
                        d[j]=d[j]-1
                        
                
                else:
                    if d[j]==0:
                        p=p+"R"
                        
                    elif d[j]>0:
                        p=p+"PR"
                        d[j]=d[j]-1
                        
        
                
                     
           
        else:
            for j in range(a-2,-1,-1):
                
                if j==a-1:
                    p=p
                elif j==0:
                    if d[j]==0:
                        p=p+"R"
                        
                    elif d[j]>0:
                        p=p+"PR"
                        d[j]=d[j]-1
                        
                
                else:
                    if d[j]==0:
                        
                        p=p+"L"
                        
                    elif d[j]>0:
                        p=p+"PL"
                        d[j]=d[j]-1
                        
        
            
        
        
          
    else:
        h=p[0]
        for i in range(1,len(p)-1):
            h=h+p[i]
        print(h)
        break