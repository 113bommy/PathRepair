import string
alp=string.ascii_lowercase
s=input()
k=int(input())
ans=''
i=0
while i<len(s)-1:
    t=s[i]
    d=(26-alp.index(t))%26
    if d<=k:
        k-=d
        ans+='a'
    else:
        ans+=t
    i+=1
if k>0:
    ans+=alp[(alp.index(s[-1])+k%26)%26]
else:
    ans+=s[-1]
print(ans)