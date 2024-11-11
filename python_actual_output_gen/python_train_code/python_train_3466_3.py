s=input()
n=len(s)
a=[0]*n
b=[0]*n
c=[0]*n
for i in range(n):
    a[i]=bool(s[i]=='a')
    if (i>0):
        a[i]+=a[i-1]
for i in range(n):
    x=0
    if (i>0):
        x=b[i-1]
    b[i]=max(a[i],x+bool(s[i]=='b'))
for i in range(n):
    x=0
    if (i>0):
        x=c[i-1]
    c[i]=max(b[i],x+bool(s[i]=='a'))
print(c[n-1])
