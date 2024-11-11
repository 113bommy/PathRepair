import re
t=int(input())
for i in range(t):
    x=input()
    r=list(x)
    alice=0
    bob=0
   
    flag=0
    
   
    n=len(r)
    while len(r)>1:
        count=0
        for k in range(len(r)-1):
            if r[k]!=r[k+1]:
                count=1
                if flag==0:
                    alice+=1
                    r=r[:k]+r[k+2:]
                    flag=1
                    break
                if flag==1:
                    bob+=1
                    r=r[:k]+r[k+2:]
                    flag=0
                    break
        
        
        if count==0 and bob>=alice:
            print("NET")
            break
        if count==0 and bob<alice:
            print("DA")
            break
        if len(r)==0 and bob>=alice:
            print("NET")
            break
        if len(r)==0 and bob<alice:
            print("DA")
            break
        
      