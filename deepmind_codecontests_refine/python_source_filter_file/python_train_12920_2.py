import string
t=int(input())
while(t):
    d1={}
    l=[str(i+1) for i in range(9)]
    da = dict.fromkeys(string.ascii_lowercase, 0)
    dA = dict.fromkeys(string.ascii_uppercase, 0)
    d1= d1.fromkeys(l,0)
    la,lA,l1=[],[],[]
    s=input()
    p=""
    for i in range(len(s)):
        if da.get(s[i])==None:
            pass
        else:
            da[s[i]]=1
            la.append(i+1)
        if dA.get(s[i])==None:
            pass
        else:
            dA[s[i]]=1
            lA.append(i+1)
        if d1.get(s[i])==None:
            pass
        else:
            d1[s[i]]=1
            l1.append(i+1)    

    if sum(list(da.values()))!=0 :
        if sum(list(d1.values())) !=0 and sum(list(dA.values())) !=0:
            p=s
            pass
        elif sum(list(d1.values())) ==0 and sum(list(dA.values())) !=0:
            if len(la)!=1:
                x=la[0]-1
                p=s[:x]+'1'+s[x+1:]
            else :
                y=lA[0]-1
                p=s[:y]+'1'+s[y+1:]
        elif sum(list(d1.values())) !=0 and sum(list(dA.values())) ==0:
            if len(la)!=1:
                x=la[0]-1
                p=s[:x]+'A'+s[x+1:]
            else :
                y=l1[0]-1
                p=s[:y]+'A'+s[y+1:]
        else:
            p="1A"+s[2:]
    else:
        if sum(list(d1.values())) !=0 and sum(list(dA.values())) !=0:
            if len(lA)!=1:
                x=lA[0]-1
                p=s[:x]+'a'+s[x+1:]
            else :
                y=l1[0]-1
                p=s[:y]+'a'+s[y+1:]
        elif sum(list(d1.values())) ==0 and sum(list(dA.values())) !=0:
            p="1a"+s[2:]
        elif sum(list(d1.values())) !=0 and sum(list(dA.values())) ==0:
            p="aA"+s[2:]
            
            #pm=[]
            #p=[]
            #for i in range(len(lA)):
                #for j in range(len(la)):
                    #pm.append(abs(lA[i]-la[j]))
                    #p.append(min(lA[i],la[j]))'''
                    
                    
    print(p)    
    t=t-1