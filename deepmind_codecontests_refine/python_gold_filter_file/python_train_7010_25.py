n,m=[int(i) for i in input().split()]
if(n==0 and m>0):
    print('Impossible')
else:
    e=m-1
    if(e<=0):
        e=0
    max=n+e
    if(m<=n):
        min=n
    else:
        min=n+(m-n)
    print(min,max)