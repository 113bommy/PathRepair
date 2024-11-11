n,a,b=map(int,input().split())
a,b=map(int,sorted([a,b]))
x=sorted(list(map(int,input().split())))[::-1]
print(sum(x[:a])/a+sum(x[a:a+b])/b)
