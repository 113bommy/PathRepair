a=int(input())
b=int(input())
c=int(input())
if a>=c and b>=c:
    print(c+1)
elif a+b==c:
    print(1)
elif (a<c and b>=c) or (b<c and a>=c):
    print(min(a,b)+1)
else:
    print(min(a,b)-1)