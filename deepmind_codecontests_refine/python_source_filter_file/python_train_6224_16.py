s=input()
p=2019
ans=0
M=[0]*p
M[0]=1
tmp=0
for i in range(len(s)):
    tmp+=(int(s[-i-1])*pow(10,i,))
    tmp%=p
    ans+=M[tmp]
    M[tmp]+=1
print(ans)