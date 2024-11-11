a=int(input())
b=int(input())
if (1<=a<=1000 and 1<=b<=1000):
    if a>b:
        n=a-b
    else:
        n=b-a
    m=n//2
    if n%2==0:
        c=(m*(m+1))
    else:
        c=((m*(m+1))//2)-(((m+1)*(m+2))//2)
print(c)
        