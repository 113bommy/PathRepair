c=input().split()
a=int(c[0])
b=int(c[1])
print(min(a,b),int(max((a-min(a,b))/2,(b-min(a,b))/2)), sep=' ')