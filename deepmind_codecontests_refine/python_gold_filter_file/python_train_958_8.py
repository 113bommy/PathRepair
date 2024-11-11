b=str(input())
lu=str(input())
if int(b)<10 and int(b)>0:
      z=b
else:
        if int(b)==0 and int(lu)==0:
                if len(b)==len(lu):
                        z=b
                else:
                        z=int(b)

        else:
                a=[]*len(b)
                lo=0
                for i in range (0,len(b)):
                        a.append(int(b[i]))


                for k in range (1,len(a)):
                        for t in range (len(a)-k):
                                if (a[t])>(a[t+1]):
                                        p=(a[t])
                                        a[t]=(a[t+1])
                                        a[t+1]=p
        
                g=0
        
                if len(a)==1 and a[0]==0:
                        z=str(0)
                
         
                else:
                
                
                        while a[0]==0:
                                a.remove(0)
                                g=g+1
                        z=a[0]
                        if len(a)==1:
                                z=int(b)
                        else:
                                del a[0]
                                q=str(a[0])
                                for i in range (1,len(a)):
                                        q+=""+str(a[i])
                                z=str(z)+str(0)*g+q
                

if lu==z:
        print("OK")
else:
        print("WRONG_ANSWER")