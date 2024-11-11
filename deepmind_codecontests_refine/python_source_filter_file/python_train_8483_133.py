m=[int(i) for i in input().split()]
a=m[0]
b=m[1]
if a>b:
    #print(b)
    a=a-b
    print(b ,int(a/2))
elif b>a:
    print(a)
    b=b-a
    print(a,int(b/2))
else:
    print(a,"0")
