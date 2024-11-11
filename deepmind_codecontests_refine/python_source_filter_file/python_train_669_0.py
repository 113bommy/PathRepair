class Point: 
      
    # Structure of a point in 2D space 
    def __init__(self, x, y): 
        self.x = x 
        self.y = y 
  
# A utility function to find square of  
# distance from point 'p' to point 'q' 
def distSq(p, q): 
    return (p.x - q.x) * (p.x - q.x) +(p.y - q.y) * (p.y - q.y) 
  
# This function returns true if (p1, p2, p3, p4)  
# form a square, otherwise false 
def isSquare(p1, p2, p3, p4): 
  
    d2 = distSq(p1, p2) # from p1 to p2 
    d3 = distSq(p1, p3) # from p1 to p3 
    d4 = distSq(p1, p4) # from p1 to p4 
  
    if d2 == 0 or d3 == 0 or d4 == 0:     
        return False
  
    # If lengths if (p1, p2) and (p1, p3) are same, then 
    # following conditions must be met to form a square. 
    # 1) Square of length of (p1, p4) is same as twice 
    # the square of (p1, p2) 
    # 2) Square of length of (p2, p3) is same 
    # as twice the square of (p2, p4) 
  
    if d2 == d3 and 2 * d2 == d4 and 2 * distSq(p2, p4) == distSq(p2, p3): 
        return True
  
    # The below two cases are similar to above case 
    if d3 == d4 and 2 * d3 == d2 and 2 * distSq(p3, p2) == distSq(p3, p4): 
        return True
  
    if d2 == d4 and 2 * d2 == d3 and 2 * distSq(p2, p3) == distSq(p2, p4): 
        return True
  
    return False
n=int(input())
for _ in range(n):
    r=[]
    for i in range(n):
        x,y,a,b=list(map(int,input().split()))
        r.append([[x,y],[a+b-y,x+b-a],[2*a-x,2*b-y],[a-b+y,a+b-x]])
    ans=64
    f=0
    r1,r2,r3,r4=r
    for i in range(4):
        for j in range(4):
            for k in range(4):
                for l in range(4):
                    p1 = Point(r1[i][0],r1[i][1]) 
                    p2 = Point(r2[i][0],r2[i][1]) 
                    p3 = Point(r3[i][0],r3[i][1]) 
                    p4 = Point(r4[i][0],r4[i][1]) 
                      
                    if isSquare(p1, p2, p3, p4):
                        f=1
                        ans=min(ans,i+j+k+l) 
    if f:
        print(ans)
    else:
        print(-1)