p=[True for i in range(1010)]
p[0]=False
p[1]=False
i=2
while i<1010:
    curr=i
    while curr*i<1010:
        p[curr*i]=False
        curr+=1
    i+=1
n=int(input())
ans=[]
c=0
for i in range(1,n+1):
    if i==n:
        ans.append([i,1])
        c+=1
    else:
        ans.append([i,i+1])
        c+=1
for i in range(1,n-1):
    if p[c]==True:
        break
    ans.append([i,i+2])
    c+=1
print(len(ans))
for i in ans:
    print(i[0],i[1])