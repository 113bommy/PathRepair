a=int(input())
b=int(input())
x=abs(b-a)//2
if x==0:
    print("1")
elif x%2==0:
    print(x*(x+1))
else:
    print((x+1)**2)
