n=int(input())
a=input().split()
for i in range(n):
    a[i]=int(a[i])
if n==1:
    print (-1)
elif n==2:
    if a[0]==a[1]:
        print (-1)
    else:
        print (1)
        print (1)
else:
    s=0
    for i in range(1,n):
        s+=a[i]
    if a[0]==a[i]:
        print (2)
        print (1,2)
    else:
        print (1)
        print (1)
