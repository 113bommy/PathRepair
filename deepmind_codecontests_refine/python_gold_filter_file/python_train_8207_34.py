n=int(input())
a=2*(n//11)
b=(n%11)//6
c=n%11 %6
print(a+b+((c+4)//5))