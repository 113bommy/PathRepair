a,b=sorted(list(map(int, input().split())))

m=b%a
while m>1:
    b=a
    a=m
    m=b%a
print(a)