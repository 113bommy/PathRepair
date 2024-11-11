n=int(input())

x=0
y=0
z=0
for i in range (n):
    a,b,c=map(int,input().split())
    x+=a
    y+=b
    z+=c
if (a==0) and (b==0) and (c==0):
    print('YES')
else:
    print('NO')
