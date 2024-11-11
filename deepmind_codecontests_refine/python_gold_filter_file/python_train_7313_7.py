import sys
input = sys.stdin.readline
from collections import defaultdict
def checker(l):
    first=int(''.join(map(str,l)))
    init=sum(l)
    for i in range(first+1,first+k+1):
        suma=[int(j) for j in str(i)]
        #print(suma)
        init+=(sum(suma))
    #print(init,n,l)
    if init!=n:
        if l[0]==9:
            l.insert(0,1)
            l[-2]=8
        else:
            l[0]+=1
            l[-2]-=1
    #print('2',l)
    return(''.join(map(str,l)))  
store=defaultdict(list)
for i in range(10):
        store[i].append(0)
        for j in range(1,10-i):
            store[i].append(store[i][-1]+j)
        for j in range(-i+1,1):
            store[i].append(store[i][-1]+j)
#print(store)
t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    
    lowest=[]
    for i in store:
        lowest.append((n-store[i][k])/(k+1))
    #print(lowest)
    ans=[]
    for i in range(len(lowest)):
        tmp=[]
        if (lowest[i])//1==lowest[i]:
            if i<=lowest[i]:
                pq=int(lowest[i])
                tmp.append(i)
                while sum(tmp)<pq:
                    tmp.append(min(pq-sum(tmp),9))
                #print(tmp,lowest[i])
                tmp.reverse()
                tmp=checker(tmp)
                ans.append(int(tmp)) 
    print(min(ans) if len(ans)>0 else -1)
            
    
            
            

    
