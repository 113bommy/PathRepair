n=int(input())
for i in range(n):
    k=10**6
    l=input().split()
    n=int(l[0])
    x=int(l[1])
    y=int(l[2])
    d=int(l[3])   
    if y%d==x%d:
        k=abs(x-y)//d
    if y%d==1:
        k=min(k,(x-2)//d+1+(y-1)//d)
    if n%d == y%d:
        k=min(k,(n-x-1)//d+1+(n-y)//d)
    if k==10**6:
        k=-1
    print(k)