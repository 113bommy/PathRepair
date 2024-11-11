n,k=map(int,input().split())
l=list(map(int,input().split()))
d={}
for i in range(n):
    d[l[i]]=0
l1=[]
cnt=0
ind=0
for i in range(n):
    if d[l[i]]!=1:
        if cnt<k:
            l1.append(l[i])
            cnt+=1
            d[l[i]]=1
        else:
            d[l1[ind]]=0
            l1.append(l[i])
            d[l[i]]=1
            ind+=1
print(cnt)
for i in range(len(l1)-1,-1,-1):
    print(l1[i],end=' ')
    