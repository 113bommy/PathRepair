q=int(input())
for o in range(q):
    n=int(input())
    a=[]
    for i in range(n):
        a.append(9)
    x=n//4
    y=n%4
    for i in range(x):
        a[n-i-1]=8
    if y!=0:
        a[n-x-1]-=1
    for i in range(n):
        print(a[i],end="")
    print()