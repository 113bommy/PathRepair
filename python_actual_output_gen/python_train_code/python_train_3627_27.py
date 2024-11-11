x,y=map(int,input().split())
if x>0:
    p1=[x+abs(y),0]
    p2=[0,[-1,1][y>0]*p1[0]]
    print(*p2,*p1)
    exit(0)
else:
    p1 = [x - abs(y), 0]
    p2 = [0, [-1, 1][y > 0] * p1[0]]
    print(*p1,*p2)