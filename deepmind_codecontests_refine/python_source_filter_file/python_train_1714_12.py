r,g,b = map(int,input().split())

l = sorted([r,g,b])
a,b,c = l
if c-a<=1:
    print((a+b+c)//3)
elif a+b>=2*c:
    print(a+b)
else:
    print((a+b+c)//3)

