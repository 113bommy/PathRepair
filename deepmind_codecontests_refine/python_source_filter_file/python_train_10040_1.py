n,m=map(int,input ().split ())
a=[int(i) for i in input ().split ()]
summ=0
for i in range(n-1):
    if a[i]+a[i+1]>m:
       summ=summ+1
    else:
       a[i+1]+a[i]
print (summ+1)