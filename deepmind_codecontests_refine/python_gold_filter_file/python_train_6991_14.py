x,y,z=list(map(int,input().split()))
if x==0 and y==0 and z!=0:
    print('?')
elif x==0 and y==0 and z==0:
    print('0')
elif x==y and x-y==z:
    print(0)
elif x>y and abs(x-y)>z:
    print("+")
elif x<y and abs(x-y)>z:
    print("-")
else:
    print("?")
