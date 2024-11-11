a=input().split(" ")
x=int(a[0])
y=int(a[1])
n=2
m=2
A = 1000000000+7
while x>1:
    m=(m%A+n%A)%A
    n =(m%A-n%A)%A
    x-=1
r1 = m
m = 2
n = 2
while y>1:
    m=(m%A+n%A)%A
    n =(m%A-n%A)%A
    y-=1
r2 = m
print((r1+r2)%A-2)