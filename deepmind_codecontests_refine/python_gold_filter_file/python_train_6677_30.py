t=int(input())
for z in range (t):
    l=list(map(int,input().split()))
    n=l[0];a=l[1];b=l[2]
    if 2*a>b:
        c=(n//2)*b+(n-2*(n//2))*a
    else:
        c=n*a
    print(c)