n=int(input())
s=input()
curr=1 
currx=0 
curry=0 
ans=0
for i in s:
    if i=='U':
        curry+=1 
    if i=='R':
        currx+=1 
    if currx>curry:
        if curr==1:
            ans+=1 
            curr=0 
    if curry>currx:
        if curr==0:
            ans+=1 
            curr=1 
print(ans-1)