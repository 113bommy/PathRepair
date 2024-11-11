n, m=(int(x) for x in input().split(' '))
if n!=1 and m!=1:
    print (1/n+(n-1)/n*(m-1)/(m*n-1))
else:
    print(1)
