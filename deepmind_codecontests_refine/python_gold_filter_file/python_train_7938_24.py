import sys


#def solve(a,b,c,d):
def solve(n,m,sx,sy):
    #print(n,m,sx,sy)

    # get top-left rect
    #if sx%2 == 0 and sy%2 == 0: # BOTH EVEN
    '''
    if sy%2 == 0: # Y EVEN
        for y in range(sy,0,-1):
            xorder = range(sx,0,-1) if y%2 == 0 else range(1,sx+1)
            for x in xorder:
                print(x,y)
    elif sx%2 == 1 and sy%2 == 1: # BOTH ODD
        for x in range(sx,0,-1):
            print(x,sy)
        for x in range(1,sx+1):
            yorder = range(sy-1,0,-1) if x%2 == 1 else range(1,sy)
            for y in yorder:
                print(x,y)
    '''
    print(sx,sy)
    print(sx,m)
    for y in range(m-1,sy,-1):
        print(sx,y)
    for y in range(sy-1,0,-1):
        print(sx,y)
    for x in range(1,sx):
        yorder = range(m,0,-1) if x%2 == 0 else range(1,m+1)
        for y in yorder:
            print(x,y)
    for x in range(sx+1,n+1):
        yorder = range(m,0,-1) if x%2 == 1 else range(1,m+1)
        for y in yorder:
            print(x,y)

if __name__ == '__main__':
    IN = [x.strip() for x in sys.stdin.readlines()]

    n,m,sx,sy = [int(x) for x in IN[0].split(' ')]
    res = solve(n,m,sx,sy)
