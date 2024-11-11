n=int(input())
a=sorted(list(map(int,input().split())))
da=[]
for i in range(n-1):
    da.append(a[i+1]-a[i])

sum=0
maxcount=0
tempcount=0
for i in range(n-1):
    if((sum+da[i])<=5):
        sum=sum+da[i]
        tempcount+=1
    elif(sum!=0):
        sum=sum-da[i-tempcount]+da[i]
    maxcount=max(maxcount,tempcount)
print(maxcount+1)
