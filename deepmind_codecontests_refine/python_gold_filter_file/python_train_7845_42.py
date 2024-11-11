i=1
m=int(input())
n=3
list=[]
while n<=360:
       if 180*(n-2)%n==0:
           x=180*(n-2)/n
           list.append(x)
       n+=1
angle=[]
while i<=m:
    a=int(input())
    angle.append(a)
    i+=1
for let in angle:
    if let in list:
        print('YES')
    else:
        print('NO')