n=int(input())
a=str(n)
b=int(a[-1])
c=0
if b==0:
    print(n)
elif 1<=b<6:
    print(n-b)
else:
    c=10-b
    print(n+c)
