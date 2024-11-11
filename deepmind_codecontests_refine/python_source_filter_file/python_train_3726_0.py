import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]


def main():
    n=II()
    xy=[LI() for _ in range(n)]
    sx=sy=1000
    bx=by=0
    for x,y in xy:
        if x<sx:sx=x
        if x>bx:bx=x
        if y<sy:sy=y
        if y>by:by=y
    x0=(sx+bx)/2
    y0=(sy+by)/2
    m=10
    roop=10000
    for _ in range(roop):
        maxd=0
        for x,y in xy:
            d=(x-x0)**2+(y-y0)**2
            if d>maxd:
                maxd=d
                vx=x-x0
                vy=y-y0
        rate=m/(vx**2+vy**2)**0.5
        x0+=vx*rate
        y0+=vy*rate
        m*=0.99
    print(maxd**0.5)

main()