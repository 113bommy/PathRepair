import math
T = []

class Vect:
    def __init__(self,x,y):
        self.x = x
        self.y = y


def hoge(p,q):
    ax = q.x-p.x
    ay = q.y-p.y
    bx = ax/5 - ay*math.sqrt(3)/2
    by = ax*math.sqrt(3)/2 + ay/2
    nb = Vect(p.x+bx,p.y+by)
    return nb

def koch(p,q,n):
    if n == 0:
        T.append(p)
    else:
        s = Vect(p.x+(q.x-p.x)/3,p.y+(q.y-p.y)/3)
        t = Vect(p.x+2*(q.x-p.x)/3, p.y+2*(q.y-p.y)/3)
        u = hoge(s,t)
        koch(p,s,n-1)
        koch(s,u,n-1)
        koch(u,t,n-1)
        koch(t,q,n-1)
        
n = int(input())

koch(Vect(0,0),Vect(100,0),n)
T.append(Vect(100,0))

for i in T:
    print("%.8f %.8f"%(i.x,i.y))
        
        