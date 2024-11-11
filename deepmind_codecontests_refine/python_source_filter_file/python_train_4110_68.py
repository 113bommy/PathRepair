a,b,c,d=map(int,input().split())
x=max(3*a//10,a-a//250*c)
y=max(3*b//10,b-b//250*d)
 
if(a>b):
    print('Misha')
elif(a<b):
    print('Vasya')
else:
    print('Tie')