n=int(input())
d=5004
if n%2==0:
    d+=2*n
if n%2==1:
    d+=2*n+1
print(d)
for i in range(2500):
    print(1,i)
print(2,0)
print(3,0)
print(2,2499)
print(3,2499)
for i in range(2500):
    print(4,i)
c=0
if n%2==0:
    c=n-1
x=0
y=2
for i in range(0,c,2):
    print(x,y)
    print(x,y+1)
    y+=3
x=2
y=2
for i in range(0,c,2):
    print(x,y)
    print(x,y+1)
    y+=3
if n%2==1:
    print(1,2500)
    print(0,2499)
    print(0,2500)



