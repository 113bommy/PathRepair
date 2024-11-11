'''Author- Akshit Monga'''
n,m=map(int,input().split())
parties=[[] for i in range(m)]
for i in range(n):
    x,y=map(int,input().split())
    parties[x-1].append(y)
for i in range(m):
    parties[i].sort(reverse=True)
mi=len(parties[0])
cost=float('inf')
for i in range(mi,n+1):
    temp=0
    to_chose=[]
    collected=mi
    for j in range(1,m):
        count=0
        for k in parties[j]:
            count+=1
            if count>=i:
                temp+=k
                collected+=1
            else:
                to_chose.append(k)
    to_chose=sorted(to_chose)
    print(collected,i)
    if collected>=i:
        cost=min(cost,temp)
    if len(to_chose)<i-collected:
        continue
    for j in range(0,i-collected):
        temp+=to_chose[j]
    cost=min(cost,temp)
print(cost)