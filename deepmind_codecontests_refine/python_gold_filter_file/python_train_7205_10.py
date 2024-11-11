x=int(input())+1
for i in range(1,x,1):
    a,b,c,d=input().split()
    a=int(a)
    b=int(b)
    c = int(c)
    d=int(d)
    import math
    mx=max(a,b,c)
    n=3*mx-a-b-c
    sum=a+b+c+d
    m=sum%3
    if m!=0 or a+b+d<=c or a+c+d<=b or b+c+d<=a or n>d:
        print('NO')
    else:
        print('YES')