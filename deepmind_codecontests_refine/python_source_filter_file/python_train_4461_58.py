x=input().split()
y=set(x)
print(y[x.count(y[0])-1])