l=list(map(int,input().split()))

c=((l[0]*l[1])/l[2])**(1/2)
a=l[0]/c
b=l[1]/a
print(round((a+b+c)*4))
