#a=[int(i) for i in input().split()]
n=int(input())
p=0
while n>0:
    n-=1
    x=input()
    a=x.split()
    flag=0
    a1=int(a[1])
    a2=int(a[2])
    if a1>=2400 and a2>a1:
        flag=1
    if flag==1:
        p=1
if p==1:
    print('YES')
else:
    print('NO')