s1=input()
s2=input()
s1=' '.join(s1)
s2=' '.join(s2)
s1=s1.split()
s2=s2.split()
a,b,c,d,e=0,0,0,0,0
for i in s1:
    if i=='+':
        a+=1
    elif i=='-':
        b+=1
for i in s2:
    if i=='+':
        c+=1
    elif i=='-':
        d+=1
    elif i=='?':
        e+=1
f=a-b
g=c-d
h=abs(f-g)
if abs(f-g)>e:
    print('0.000000000000')
elif h<=e:
    x=int((h+e)/2)
    a1=1
    a2=1
    a3=1
    for i in range(1,e+1):
        a1=a1*i
    for i in range(1,x+1):
        a2=a2*i
    for i in range(1,e-x+1):
        a3=a3*i
    y=a1/(a2*a3)
    i=y*(0.5**e)
    print('%.12f'%i)
        
