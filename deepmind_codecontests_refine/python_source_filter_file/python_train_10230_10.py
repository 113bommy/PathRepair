from collections import Counter
from operator import itemgetter 

for x in range(int(input())):
    s =input()
    n=len(s)
    p={}
    for i in range(n):
        if s[i] not in p:
            p[s[i]]=i
    d=Counter(s)
    j=sorted(d.items(),key=itemgetter(1), reverse=True)
    #print(p,j)
    if j[0][1]>n//2:
        print(n-j[0][1])
    else:
        mx=j[0][1]
        for i in range(len(j)-1):
            
            
            for u in range(i+1,len(j)):
                if p[j[i][0]]<p[j[u][0]]:
                    t=0
                else:
                    t=1
                r=t
                l=0
                for k in range(n):
                    #print(l)
                    if s[k]==j[i][0] and t==0:
                        l+=1
                        t=1-t
                    elif s[k]==j[u][0] and t==1:
                        l+=1
                        t=1-t
                if t!=r:
                    l-=1
                
                mx=max(mx,l)
                        
                        
                
                
            
    print(n-mx)