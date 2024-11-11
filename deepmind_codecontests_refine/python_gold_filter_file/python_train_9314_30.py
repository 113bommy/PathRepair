n, x1, y1 = [int(s) for s in input().split()] 
slope = {}
shoot=0
for i in range(n):
    x2,y2=[int(s) for s in input().split()]
    if(x2-x1)==0:
        m="a"
    else:
        m = (y2-y1)/(x2-x1)
    
    if m not in slope:
        shoot+=1
        slope[m] = 0
print(shoot)
