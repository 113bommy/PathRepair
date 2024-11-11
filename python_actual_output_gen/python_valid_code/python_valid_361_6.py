s=list(map(int,input().split()))
n=s[0]
t=s[1:]
t.sort()
a,b,c=t
r=[0 for i in range(n)]
if n>=a:r[a-1]=1
if n>=b:r[b-1]=1
if n>=c:r[c-1]=1
for i in range(1,n):
    temp=[r[i]]
    if i>a and r[i-a]>0:
        temp.append(r[i-a]+1)
    if i>b and r[i-b]>0:
        temp.append(r[i-b]+1)
    if i>c and r[i-c]>0:
        temp.append(r[i-c]+1)
    r[i]=max(temp)
print(r[n-1])
