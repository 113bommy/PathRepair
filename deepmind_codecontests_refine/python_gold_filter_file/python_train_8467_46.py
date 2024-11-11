n=int(input())
a=[]
a.append(0)
a.append(1)
a.append(1)
a.append(2)
if n==0:print(*[0,0,0])
elif n==1:print(*[0,0,1])
elif n==2:print(*[0,1,1])
else:
    for i in range(4,n+2):
        a.append(a[i-1]+a[i-2])
        if a[i]==n:
            print(*[a[i-4],a[i-3],a[i-1]])
            break