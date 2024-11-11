a,b,c,d = map(int,input().split())
if(a==c and b==d):
    rook = 0
elif(a==c or b==d):
    rook = 1
else:
    rook = 1+1

king = max(abs(a-c),abs(b-d))

if(abs(a-c)%2 != abs(b-d)%2!=0):
    bishop = 0
else:
    if(a==c and b==d):
        bishop = 0
    elif(abs(a-c) == abs(b-d)):
        bishop = 1
    else:
        bishop = 1+1
print(rook,bishop,king)