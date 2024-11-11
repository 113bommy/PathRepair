n,b=map(int,input().split())
arr=list(map(int,input().split()))
e=0
o=0
arr1=[]
for i in range(n):
    if(arr[i]%2==0):
        e+=1
    else:
        o+=1
    if(e==o):
        if(i!=n-1):
            arr1.append(arr[i+1]-arr[i])
#print(arr1)
arr1.sort()
ans=0
sumx=0
i=0
while(sumx<b and i<len(arr1)):
    if(sumx+arr1[i]<=b):
        ans+=1
        sumx+=arr1[i]
    i+=1
print(ans)

