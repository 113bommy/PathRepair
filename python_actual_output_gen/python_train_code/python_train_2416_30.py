x,y,z = list(map(int, input().split()))

if x+z>=y and x>=y+z:
    print('+')
elif x+z==y and x==y+z:
    print('0')
elif x+z<=y and x<=y+z:
    print('-')
else:
    print('?')