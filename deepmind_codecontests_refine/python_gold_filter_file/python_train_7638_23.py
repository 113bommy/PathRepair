n,m,d=map(int,input().split())
l=[]
for i in range(n):
    l.append(list(map(int,input().split())))
min1=10000000000
dic={}
for i in range(n):
    for j in range(m):
        if dic.get(l[i][j])==None:
            dic[l[i][j]]=1
        else:
            dic[l[i][j]]+=1

        if l[i][j]<min1:
            min1=l[i][j]
sum=0
l=sorted(dic.keys())
for i in l:
   k=0
   if (i-min1)%d==0:
       k=1
       sum+=((i-min1)*dic[i])//d
   if k==0:
       break
if k==0:
    print(-1)
else:
    s1=[dic[l[0]]]
    s2=[dic[l[-1]]]
    min2=sum
    ind=1
    min1=min(l)
    max1=max(l)
    for i in range(1,len(l)):
        s1.append(s1[i-1]+dic[l[i]])
        s2.append(s2[i-1]+dic[l[len(l)-1-i]])
    for i in range(min1+d,max1+1,d):
        if i==l[ind]:
            sum=sum+s1[ind-1]-s2[len(l)-1-ind]
            ind+=1
        elif l[ind]>i:
            sum=sum+s1[ind-1]-s2[len(l)-1-ind]
        if sum<min2:
            min2=sum
    print(min2)

