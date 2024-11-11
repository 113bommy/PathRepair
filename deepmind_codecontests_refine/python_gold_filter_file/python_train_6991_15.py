x,y,z=[int(i) for i in input().split()]
if x-y>0 and x-y>z:
    print('+')
elif (x-y)<0 and -(x-y)>z:
    print('-')
elif x==y and z==0:
    print('0')
else:
    print('?')