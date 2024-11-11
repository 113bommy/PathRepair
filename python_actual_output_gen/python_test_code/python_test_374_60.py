n=int(input())
l=list(input())
if(l.count('n')>0):
    print( '1'+' 1'*(l.count('n')-1)+' 0'*l.count('z'))
else:
    print('0'*l.count('z'))