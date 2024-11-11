n,m,k=map(int,input().split())
ar=list(map(int,input().split()))
page=k
obj=0
temp=0
count=0
i=0
while i<m:
    if ar[i]-obj<=page:
        temp+=1
        i+=1
        continue
    if temp!=0: count+=1
    obj+=temp
    temp=0
    if (ar[i]-obj)>page: 
        page+=k*(int((ar[i]-obj-page+k-1)/k))
    i-=1
if temp!=0: count+=1
print(count)
        