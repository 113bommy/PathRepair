n,m,a,b = [int(x) for x in input().split()]

if(a*m <= b):
    print(n*a)
else:
    print(a*(n%m) + b * int(n/m))