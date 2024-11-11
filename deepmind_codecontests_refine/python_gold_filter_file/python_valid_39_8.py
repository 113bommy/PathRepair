import sys 
input = lambda:sys.stdin.readline().strip()
t = int(input())
while t:
    t-=1
    ans = float('inf')
    W,H = map(int,input().split())
    x1,y1,x2,y2 = map(int,input().split())
    w1,h1 = map(int,input().split())
    w,h = x2-x1,y2-y1 
    if w+w1<=W:
        # Left of the table
        dist = w1-x1 
        ans = min(ans,dist)
        # Right of the table
        dist = x2-(W-w1)
        ans = min(ans,dist)
    if h+h1<=H:
        # Top of the table
        dist = y2-(H-h1)
        ans = min(ans,dist)
        # Bottom of the table
        dist = h1-y1 
        ans = min(ans,dist)
    ans = max(ans,0)
    if ans==float('inf'):
        print(-1)
    else:
        print(ans)
        
    
        
            
        
        
        
    