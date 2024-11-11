n,x,y=input().split()
n,x,y=[int(n),int(x),int(y)]
a=input()
i=n-1
j=i-y
ans=0
if a[j]=='0':
    ans+=1
while i>(n-x):
    if i!=j:
        if a[i]=='1':
            ans+=1
    i-=1
print(ans)