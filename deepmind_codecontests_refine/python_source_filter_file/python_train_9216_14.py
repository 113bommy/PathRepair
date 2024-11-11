n,a,b,c,d= [int(x) for x in input().split()]
l=[a+b,a+c,b+d,c+d]
print (n*(n-max(l)+min(l)))