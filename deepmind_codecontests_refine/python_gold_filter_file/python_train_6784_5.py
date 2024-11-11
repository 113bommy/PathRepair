a=input()
b=input()
n=len(a)
m=len(b)
c=0;e=0;o=0
for i in range(m):
    if a[i]!=b[i]:
        c+=1
if c%2==0:
    e+=1
else:
    o+=1
for i in range(n-m):
    if a[i]==a[i+m]:
        if c%2==0:
            e+=1
        else:
            o+=1
    else:
        if c%2==0:
            o+=1
            c=1
        else:
            e+=1
            c=0
print(e)