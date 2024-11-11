n=int(input())
a=list(map(int,input().split(" ")))
mn=a[0];ff=0;fl=0;mx=0;t=0;c=0
for i in range(len(a)):
    if (a[i]<mn):
        mn=a[i]
        ff=i
        fl=i
        t=1
    elif (a[i]==mn):
        t+=1
        fl=i
mx=len(a)-(fl-ff+1)
for i in range(ff+1,fl):
    if (a[i]==mn):
        if (c>mx):
            mx=c
        c=0
    else:
        c+=1
print(mx+mn*len(a))

        
