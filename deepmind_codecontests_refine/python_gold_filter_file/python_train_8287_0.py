n=int(input())
a=float(input())
b=float(input())
c=float(input())
if n<2:
    print(0)
else:
    print(int((n-2)*min(a,b,c)+min(a,b)))
