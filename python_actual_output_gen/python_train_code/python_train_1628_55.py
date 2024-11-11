a,b,c=map(int,input().split(' '))
d=max(a,b,c)
e=a+b-d
if e>d:
    print(0)
elif e==d:
    print(1)
else:
    print(d-e+1)