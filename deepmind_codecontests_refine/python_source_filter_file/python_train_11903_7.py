k=int(input())
s=str(input())
n=len(s)
x=0
y=1
lis=[0]
a=0
if k==0:
    a=0
    ans=0
    for i in range(n):
        if s[i]=="0":
            a+=1
        else:
            if a>0:
                ans+=((a*(a+1))//2)
            a=0
    if a>0:
        ans+=(2**(a-1))
    print(ans)
else:
    for i in range(n):
        if s[i]=="1":
            a+=1
        lis.append(a)
    ans=0
    while x<=n and y<=n:
        if lis[y]-lis[x]==k:
            temp1=lis[y]
            temp2=lis[x]
            b=0
            a=0
            while y<=n and lis[y]==temp1:
                y+=1
                b+=1
            while x<=n and lis[x]==temp2:
                x+=1
                a+=1
            ans+=(a*b)
        elif lis[y]-lis[x]<k:
            if y==x:
                x=y
                y+=1
            else:
                y+=1
        else:
            x+=1
    print(ans)
