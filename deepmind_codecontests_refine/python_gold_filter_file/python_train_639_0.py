n,m,k=map(int,input().split())
l=list(map(int,input().split()))
count=0
lim=k
flag=0
time=0
while len(l)>0:
    if l[0]<=lim:
        l.remove(l[0])
        count+=1
        flag=1
    elif l[0]>lim and flag==1:
        time+=1
        flag=0
        lim+=count
        count=0
    elif l[0]>lim and flag==0:
        if lim+k<=n:
            lim=lim+((l[0]-lim-1)//k+1)*k
        else:
            lim=n
if flag==1:
    time+=1
print(time)






