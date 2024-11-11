import string
n,k=map(int,input().split())
num=[0]+list(map(int,input().split()))+[0]
s='$'+input()+'$'
val=1
data=[]
data.append(num[0])
if n==1:
    print(sum(data))
    exit()
ans=0
for i in range(1,n+2):
    if s[i]==s[i-1]:
        data.append(num[i])
    else:
        data.sort(reverse=True)
        if len(data)>k:
            ans+=sum(data[:k])
        else:
            ans+=sum(data)
        data=[num[i]]
    # print(data,ans)
print(ans)
        

