from collections import namedtuple

Point = namedtuple("Pont",["x","y"])

def f( p1 , p2 , p3 ):

    if p1.x == p2.x and ( p3.y >= max(p1.y,p2.y) or p3.y <= min(p1.y,p2.y) ) :
        return True

    if p1.y == p2.y and ( p3.x >= max(p1.x,p2.x) or p3.y <= min(p1.x,p2.x) ):
        return True

    return False

if __name__ == "__main__":

    x1, y1 = [int(x) for x in input().split()]
    x2, y2 = [int(x) for x in input().split()]
    x3, y3 = [int(x) for x in input().split()]

    p1 = Point(x=x1,y=y1)
    p2 = Point(x=x2,y=y2)
    p3 = Point(x=x3,y=y3)

    if (p1.x == p2.x and p2.x == p3.x) or (p1.y == p2.y and p2.y == p3.y):
        print(1)
    elif f(p1,p2,p3) or f(p1,p3,p2) or f(p2,p3,p1):
        print(2)
    else:
        print(3)