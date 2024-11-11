def sum(a):
    s=0
    for i in a:
        s=s+i
    return s
n=int(input())
a=list(map(int,input().split()))
x=sum(a)
if a[0]>=x//2+1:
    print(1)
    print(1)
else:
    z=[1]
    s=a[0]
    for i in range(1,len(a)):
        if a[0]//2>=a[i]:
            z.append(i+1)
            s=s+a[i]
            a[i]=0
    a[0]=0
    if len(z)==1 or sum(a)>=s:
        print(0)
    else:
        print(len(z))
        for i in z:
            print(i,end=" ")

