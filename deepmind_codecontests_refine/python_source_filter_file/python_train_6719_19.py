n,a=map(int,input().split())
l=[int(ele) for ele in input().split()]
if a==1 or a==n:print(l.count(1));exit()
n,a=n-1,a-1
count=0
if l[a]==1:count+=1;l[a]==0
for i in range(1,min(n-a,a)+1):
    if l[a+i]==l[a-i]==1:
        count+=1
    l[a+i],l[a-i]=0,0
count+=l.count(1)
print(count)