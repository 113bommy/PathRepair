l=int(input())
s=input().strip()
count=0
res=[]
x=[]
y=[]
a=[]
for i in range(0,l-1,2):
    x.append(s[i])
    y.append(s[i+1])
    for j in range(i,l-1):
        if(s[i] == s[j])and(s[i+1]==s[j+1]):
            count+=1
    res.append(count)
    count=0
#for i in res:print(i,end=" ")
m=max(res)
count=0
for i in range(0,l-1,2):
    x.append(s[i])
    y.append(s[i+1])
    for j in range(i,l-1):
        if(s[i] == s[j])and(s[i+1]==s[j+1]):
            count+=1
    if(count == m):
        a.append(s[i])
        a.append(s[i+1])
        break
    count=0
ans=''.join(a)
print(ans)
