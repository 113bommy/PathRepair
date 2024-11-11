a=int(input())
r=[]
b=[]
x=sorted(list(map(int,input().split())))
for i in range(a):
    if i%2==0:
        r.append(x[i])
    else:
        b.append(x[i])
pi=3.1415926535
area=0

for i in r:
    area+=i**2*pi
for i in b:
    area-=i**2*pi

print(area)
