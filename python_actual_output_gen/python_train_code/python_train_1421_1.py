a,b,c,d=map(int,input().split())
m,v=max((0.3*a),(c*(a/250))),max((0.3*b),(d*(b/250)))

if(m==v):
    print('Tie')
elif(m>v):
    print('Misha')
else:
    print('Vasya')