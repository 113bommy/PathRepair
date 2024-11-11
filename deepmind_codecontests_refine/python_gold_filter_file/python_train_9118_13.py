n,s=int(input()),input()
ans=''
curr=0
for x in s:
    if x=='1':
        curr+=1
        curr%=10
    else:
        ans=ans+str(curr)
        curr=0
#if curr > 0:
ans+=str(curr)
print(ans)