from collections import defaultdict
n=int(input())
a=list(map(int,input().split()))
d={};b=defaultdict(list);c=0;ms=['A','B'];w=['']*n;k=l=A=B=0;x=-1
for i in range(n):
    if a[i] in d:
        d[a[i]]+=1
    else:
        d[a[i]]=1
    b[a[i]].append(i)
for i in d.keys():
    if d[i]==1:
        c+=1
    elif d[i]%2==1:
        x=i
#print (d)
if c%2==0:
    print ('YES')
    for i in d.keys():
        if d[i]>1:
            for j in b[i]:
                w[j]=ms[k%2]
            k+=1
            #print (w)
        else:
            w[b[i][0]]=ms[l%2]
            l+=1
    print (''.join(w))
elif x>=0:
    print ('YES')
    for i in d.keys():
        if d[i]>1:
            if i==x:
                pass
            else:
                for j in b[i]:
                    w[j]=ms[k%2]
            k+=1
        else:
            w[b[i][0]]=ms[l%2]
            if ms[l%2]=='A':
                A+=1
            else:
                B+=1
            l+=1
    #print (b[x])
    for i in range(len(b[x])-1):
        if A>B:
            w[b[x][i]]=ms[0]
        else:
            w[b[x][i]]=ms[1]
    if A>B:
        w[b[x][-1]]=ms[1]
    else:
        w[b[x][-1]]=ms[0]
    print (''.join(w))
else:
    print ('NO')
