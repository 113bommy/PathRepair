n,k=list(map(int,input().strip().split()))
list1=list(map(int,input().strip().split()))
list1.sort()

maxima=list1[n-1]

m=dict()
curr=2
count=0
for i in range(n):
    if list1[i]!=curr:
        for j in range(curr,list1[i]):
            m[j]=count
        curr=list1[i]
    count+=1

for j in range(curr,maxima+1):
    m[j]=count


for j in range(maxima,1,-1):
    if j==maxima:
        continue
    m[j]=max(m[j],m[j+1]-1)



for i in range(n-1,0-1,-1):
    if i==n-1:
        temp=list1[n-1]
    else:
        temp=max(list1[i],temp-1)

start=temp
        

ans=[]
while(1):
    if m[start]<k:
        ans.append(start)
    else:
        break
    
    start+=1

print(len(ans))
for val in ans:
    print(val,end=" ")
print()





