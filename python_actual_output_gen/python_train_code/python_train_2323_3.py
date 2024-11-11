n=int(input())
s=input()
carry=1
ans=[0]
if(s[0]=='0'): 
    print(1)
else:
    for i in range(1,n):
        if(s[i]=='0' and carry==1):
            ans.append(1)
            carry=0
            
        elif(s[i]=='0' and carry==0):
            ans.append(0)
            carry=0
            
        elif(s[i]=='1' and carry==1):
            ans.append(0)
            carry=1
            
        elif(s[i]=='1' and carry==0):    
            ans.append(0)
            
            carry=0
    #print(ans)
    c=0
    for i in range(n):
        if(int(s[i])!=ans[i]):
            c+=1
    print(c)        
    
            
            