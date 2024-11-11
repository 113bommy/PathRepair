n,k=map(int,input().split())
p=0
l=0
if n==0 and k==0:
    print('0 0')
elif n==0:
    print('Impossible')
elif k==0:
    print(n,' ',n)
else:
    if n>k:
        print(n)
    else:
        m=k-n
        print(m+n)
    l=n+k-1
    print(l)