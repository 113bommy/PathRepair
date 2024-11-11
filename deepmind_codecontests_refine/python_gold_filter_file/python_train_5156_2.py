n=int(input())
a=n//10000
b=n//1000%10
c=n//100%10
d=n//10%10
e=n%10
m=a*10000+c*1000+e*100+d*10+b
print(format(m**5%100000,'05d'))
