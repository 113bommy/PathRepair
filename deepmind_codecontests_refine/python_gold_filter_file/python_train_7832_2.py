def corona(n,a):
    
    if a[1]-a[0]>0:
        slope="+"
    else:
        slope="-"
    
    x=[0]
    last=None
    for i in range(1,n):
        if a[i]>a[i-1]:
            if slope=="+":
                last=i
            else:
                x.append(last)
                slope="+"
                last=i
        else:
            if slope=="-":
                last=i
            else:
                x.append(last)
                slope="-"
                last=i
        if i==n-1:
            x.append(last)
    print(len(x))
    for j in x:
        print(a[j],end=" ")
    print()
    return

t=int(input())
a=[]
for i in range(t):
    b=int(input())
    c=list(map(int,input().split(" ")))
    a.append([b,c])
for x in a:
    corona(*x)