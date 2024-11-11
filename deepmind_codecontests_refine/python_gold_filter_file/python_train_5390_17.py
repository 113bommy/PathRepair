n=int(input())
a=list(input())
c=a.count("W")
b=a[:n-c]
d=b.count("W")
print(d)
