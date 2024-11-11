n=int(input())
t=list(input())
s=list(input())
a=[0]*27
b=[0]*27
for i in range(n):
    a[ord(t[i])-97]+=1
    b[ord(s[i])-97]+=1
f=0
for i  in range(27):
    if a[i]!=b[i]:
        f=1
        break
if f==1:
    print(-1)
else:
    cnt=0
    ans=[]
    for i in range(n):
        for j in range(n):
            if s[i]==t[j]:
                s[j]=0
                break
        x=j
        if j>i:
            y=x-1
        else:
            y=x+1
        while x!=i:
            t[x],t[y]=t[y],t[x]
            cnt+=1
            if i<j:
                ans.append(y + 1)
                x-=1
                y-=1
            else:
                ans.append(x + 1)
                x+=1
                y+=1
        t[x]=0
    print(cnt)
    print(*ans,sep=" ")