a=int(input())
b=int(input())
l=list(range(1,(a+b+2)))
if(a==0):
    print(*l[::-1])
else:
    p=l[1:1+b]
    del l[1:1+b]
    print(*l+p)