P = list(map(int,input().split()))
def output(r,x,y,X,Y):
    dist = ((X-x)**2 + (Y-y)**2)**0.5
    if dist%(2*r) == 0:
        return dist//(2*r)
    return dist//(2*r) + 1    
print(output(P[0],P[1],P[2],P[3],P[4]))    