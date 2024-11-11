t=int(input())
while t>0:
    t-=1
    #a,b=map(int,input().split())
    n=int(input())
    l=list(map(int,input().split()))
    l.sort()
    dic={}
    for i in l:
        if i in dic.keys():
            dic[i]+=1
        else:
            dic[i]=1
    party=1
    spare=0
    #print(dic)
    for k,v in dic.items():
        #print(k,v)
        if party+v-1 + spare>=k:
            party=party+v+spare
            spare=0
        else:
            spare=v
    print(party)
        
    
            
            
        
