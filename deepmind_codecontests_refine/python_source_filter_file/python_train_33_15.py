from math import sqrt

a,b,c=map(int,input().split())
if a==b==c==0:
    print(-1)
elif a==b==0:

    print(0)
elif a==0:
    print(1)
    print(-c/b)
else:
    if b**2==(4*a*c):

        print(1)
        print((-b)/2*a)
    elif (4*a*c)>b**2:
        print(-1)
    else:
        print(2)
        x=((-b+sqrt(b**2-(4*a*c)))/(2*a))
        y=(-b - sqrt(b ** 2 - (4 * a * c))) / (2 * a)
        print('{0:.16f}'.format(min(x,y)))
        print('{0:.16f}'.format(max(x,y)))