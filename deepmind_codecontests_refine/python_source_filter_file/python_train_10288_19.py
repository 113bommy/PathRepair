N=int(input())
XYH = [[int(a) for a in input().split(" ")] for i in range(N)]
for cx in range(0, 101):
    for cy in range(0, 101):
        Hp = [abs(x-cx)+abs(y-cy)+h for x, y, h in XYH if h>0]
        Hz = [Hp[0]-abs(x-cx)-abs(y-cy) for x,y,h in XYH if h==0] 
        if all([h==Hp[0] for h in Hp]) and all([h>=0 for h in Hz]):
            print(" ".join([str(cx),str(cy),str(Hp[0])]))