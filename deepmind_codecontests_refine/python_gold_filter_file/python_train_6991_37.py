xyz=input().split()
x=int(xyz[0])
y=int(xyz[1])
z=int(xyz[2])
if x > y:
    if x-y > z:
        print('+')
    else:
        print('?')
elif x < y:
    if y-x > z:
        print('-')
    else:
        print('?')
else:
    if z > 0:
        print('?')
    else:
        print(0)