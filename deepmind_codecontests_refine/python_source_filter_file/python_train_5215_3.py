s=input()
n=len(s)
suma=0
c=0
a=[]
for i in range(n):
    a.append(int(s[i])%3)
    if a[i]==0:
        c+=1
for i in range(n):
    if a[i]==1:
        if i<n-1:
            if a[i+1]==2:
                c+=1
                a[i]=0
                a[i+1]=0
                continue
        if i<n-2:
            if a[i+1]==1 and a[i+2]==2:
                c+=1
                a[i]=0
                a[i+1]=0
                a[i+2]=0
                continue
        continue
    if a[i]==2:
        if i<n-1:
            if a[i+1]==1:
                c+=1
                a[i]=0
                a[i+1]=0
                continue
        if i<n-2:
            if a[i+1]==2 and a[i+2]==2:
                c+=1
                a[i]=0
                a[i+1]=0
                a[i+2]=0
                continue
        continue
#print(*a)
print(c)