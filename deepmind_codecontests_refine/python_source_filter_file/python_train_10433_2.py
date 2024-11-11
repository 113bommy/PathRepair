def main():
    def tt(x0,y0,x1,y1):
        return abs(x1 - x0) + abs(y1 - y0)
    
    x0,y0,ax,ay,bx,by = map(int,input().split())
    xs,ys,t = map(int,input().split())
    
    points = [[1,1]]
    
    x1, y1 = x0, y0
    #while tt(xs,ys,x1,y1) < t:
    n = 62
    while n > 0:
        x1 = ax * x1 + bx
        y1 = ay * y1 + by
        points.append([x1,y1])
        n -= 1
        
    #print(points)
    
    ans = 0
    for i in range(len(points)):
        for j in range(i,len(points)):
            cur_t = tt(*points[i],*points[j]) + min(tt(xs,ys,*points[i]),tt(xs,ys,*points[j]))
            #print()
            #print(points[i],points[j],cur_t)
            if cur_t <= t:
                ans = max(ans, j - i + 1)
    
    print(ans)

main()
        
    
    
    
