n=int(input())
while(n>0):
    n-=1
    s=input()
    l=u=d=-1
    a=b=0
    for i in range(len(s)):
        if(s[i].isupper()):
            u=i
        elif(s[i].islower):
            l=i
        else:
            d=i
    if(l!=-1 and u!=-1 and d!=-1):
         print(s)
    elif((l==-1 and u==-1)):
         print("Ss"+s[2:])
    elif((d==-1 and u==-1)):
         print("1S"+s[2:])
    elif((l==-1 and d==-1)):
         print("1s"+s[2:])
    elif(l==-1):
         for i in range(len(s)):
             if(s[i].isupper):
                 a+=1
             else:
                 b+=1
             if(a==2 or b==2):
                 print(s[0:i]+"s"+s[i+1:])
                 break
    elif(u==-1):
         for i in range(len(s)):
             if(s[i].islower):
                 a+=1
             else:
                 b+=1
             if(a==2 or b==2):
                 print(s[0:i]+"S"+s[i+1:])
                 break
    else:
         for i in range(len(s)):
             if(s[i].isupper):
                 a+=1
             else:
                 b+=1
             if(a==2 or b==2):
                 print(s[0:i]+"1"+s[i+1:])
                 break
        
    
    
