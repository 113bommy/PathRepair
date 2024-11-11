# import sys
# sys.stdin=open('input.txt', 'r')
# sys.stdout=open('output.txt', 'w')

d, _, c=[k for k in input().split()]
if c=='week':
    if d==5 or d==6:
        print('53')
    else: print('52')
else:
    if d==30:
        print('11')
    elif d==31:
        print('7')
    else: print('12')