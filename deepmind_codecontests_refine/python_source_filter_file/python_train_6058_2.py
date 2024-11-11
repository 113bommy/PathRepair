n=int(input())
a=[int(x) for x in input().split()]
b=[int(x) for x in input().split()]

vis=[False]*n
s=sorted(zip(a,b))

c=1
L1=[]
L2=[]
ans=0
h=s[0][1]
for i in range(1,len(s)):
    if(s[i][0]!=s[i-1][0]):
        if(c>1):
            L1.append(s[i-1][0])
            ans+=h
        else:
            L2.append(s[i-1])
        c=1
        h=s[i][1]
    else:
        c+=1
        h+=s[i][1]
    
if(c>1):
    L1.append(s[-1][0])
    ans+=s[-1][1]
else:
    L2.append(s[-1])

for i in range(0,len(L2)):
    for j in range(0,len(L1)):
        if(L2[i][0]|L1[j]==L1[j]):
            ans+=L2[i][1]
            break

print(ans)


