n=int(input())
s=str(input())
l=[0]
for i in range(len(s)):
    if ord(s[i])>=65 and ord(s[i])<=90:
        l.append(i)
ans=0
l.append(n-1)
for i in range(len(l)-1):
    ls=[]
    for j in range(l[i],l[i+1]):
        if s[j] not in ls and (ord(s[j])>=97 and ord(s[j])<=122):
            ls.append(s[j])
    ans=max(ans,len(ls))
    #print(ls)
print(ans)

