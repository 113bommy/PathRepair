s = input()

v = 0
h = 0

for i in list(s):
    if i == '0':
        if v == 0:
            print( 1, 1 )
            v+=1
        else:
            print( 1, 3 )
            v = 0
    else:
        h += 1
        print( 2, h )
        h %= 4
