l=list(map(int,input().split()))

a=((l[0]*l[1])/l[2])**(1/2)
c=l[0]/a
b=l[1]/a
print(round((a+b+c)*4))

