from collections import defaultdict as dd
n=int(input())
l=[]
d=dd(list)
d2=dd(list)
for _ in range(n-2):
    a,b,c=map(int,input().split())
    l+=[[a,b,c]]
    
for i in range(n-2):
    d[l[i][0]]+=[i]
    d[l[i][1]]+=[i]
    d[l[i][2]]+=[i]
for i in range(n-2):
    d2[(l[i][0],l[i][1])]+=[l[i][2]]
    d2[(l[i][1],l[i][2])]+=[l[i][0]]
    d2[(l[i][2],l[i][1])]+=[l[i][0]]
    d2[(l[i][1],l[i][0])]+=[l[i][2]]
    d2[(l[i][0],l[i][2])]+=[l[i][1]]
    d2[(l[i][2],l[i][0])]+=[l[i][1]]
for i in d:
    if(len(d[i])==1):
        k=i
        break
ans=[k]
bef=k
#print(d,k)
for i in d:
    if (len(d[i])==2):
        for j in d[i]:
            if j==d[k][0]:
               
                p=i
                break

ans+=[p]
ind=d[k][0]
#print(ans)
'''
for i in d[tuple(ans)]:
    if i not in ans:
        ans+=[i]
        nex+=[i]
        break
'''
nex=[ans[0],ans[1]]
#print(ans)
bef=99999999999999
for i in range(n-2):
    for j in d2[tuple(nex)]:
        if j !=bef:
            ans+=[j]
    bef=nex.pop(0)
    nex+=[ans[-1]]
print(*ans)
    
    
    
