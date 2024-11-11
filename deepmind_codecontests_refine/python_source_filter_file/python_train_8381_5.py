string=input()
n=len(string)-1
ans=0
for i in range(n-1):
    if int(string[i])%4==0:
        ans+=1
    temp=string[i:i+2]
    if temp[0]=='0':
        temp=string[i+1]
    if(int(temp)%4==0):
        ans=ans+i+1
        
if(int(string[-1])%4==0):
    ans=ans+1
print(ans)
