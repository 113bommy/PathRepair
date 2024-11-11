from collections import defaultdict as dd
t=1
d=dd(list)
for _ in range(t):
    n,k=map(int,input().split())
    arr=list(map(int,input().split()))
    arr.sort()
    for i in range(n):
        j=arr[i]
        d[j]+=[0]
        co=1
        while(j!=0):
            j=j//2
            if(j in d):
                d[j]+=[d[j][-1]+co]
            else:
                d[j]+=[co]
            co+=1
    mini=999999
    #print(d)
    for i in d:
        if(len(d[i])>=k):
            mini=min(d[i][k-1],mini)
    print(mini)
        
        
    