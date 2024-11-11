x,y,z=map(int,input().split())
if(x>y and abs(x-y)>z):
    print('+')
elif(y>x and abs(x-y)>z):
    print('-')
elif(x==y and z==0):
    print('0')
elif(abs(x-y)<=z):
    print('?')