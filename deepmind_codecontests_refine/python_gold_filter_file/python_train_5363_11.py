n,p,q=map(int,input().split())
ch=input()
l=len(ch)

idx1=0
idx2=0


if((n%p)==0):
    print(n//p)
    #print("shit1")
    idx1=0
    for i in range(n//p):
        
        print(ch[idx1:idx1+p])
        idx1+=p
elif((n%q)==0):
    print(n//q)
    #print("shit2")
    for i in range(n//q):
        
        print(ch[idx2:idx2+q])
        idx2+=q
else:
    if((n%p)%q)==0:
        print((n//p)+((n%p)//q))
        #print("shit3")
        for i in range(n//p):
            print(ch[idx1:idx1+p])
            idx1+=p
        idx2=idx1    
        for i in range((n%p)//q):
            
            print(ch[idx2:idx2+q])
            idx2+=q
    elif((n%q)%p)==0:
        print((n//q)+((n%q)//p))
        #print("shit4")
        for i in range(n//q):
            print(ch[idx2:idx2+q])
            idx2+=q
        idx1=idx2
        for i in range((n%q)//p):
            
            print(ch[idx1:idx1+p])
            idx1+=p

    else:
        nb1=n
        nb2=0
        while(((nb1%q)!=0) and (((nb1-p)>=0))):
            nb1-=p
            nb2+=1
        if((nb1%q)==0):
            print((nb2)+(nb1//q))
            #print("shit5")
            for i in range(nb2):
                print(ch[idx1:idx1+p])
                idx1+=p
            idx2=idx1
            for i in range(nb1//q):
                
                print(ch[idx2:idx2+q])
                idx2+=q
        
        elif((nb1%q)!=n):
            nb1=n
            nb2=0
            while(((nb1%p)!=0) and (nb1-q>=0)):
                nb1-=q
                nb2+=1
            if((nb1%p)==0):
                print((nb2)+(nb1//p))
                #print("shit6")
                for i in range(nb2):
                    print(ch[idx1:idx1+q])
                    idx1+=q
                idx2=idx1
                for i in range(nb1//p):
            
                    print(ch[idx2:idx2+p])
                    idx2+=p
            else:
                print(-1)



    




    
