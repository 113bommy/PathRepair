def solve1(x, y, d, n): # n - d > d
    if (x <= d):
        y1 = -x + d
        y2 = x + d
        
        if (y >= y1) and (y <= y2):
            return True
        return False
    elif (x <= (n-d)):
        y1 = x - d
        y2 = x + d
        
        if (y >= y1) and (y <= y2):
            return True
        return False
    else:
        y1 = x - d
        y2 = -x + 2 * n - d
        
        if (y >= y1) and (y <= y2):
            return True
        return False

def solve2(x, y, d, n):
    if (x <= (n-d)):
        y1 = -x + d
        y2 = x + d
        
        if (y >= y1) and (y <= y2):
            return True
        return False
    elif (x <= d):
        y1 = d - x
        y2 = -x + 2 * n -d
        
        if (y >= y1) and (y <= y2):
            return True
        return False
    else:
        y1 = x - d
        y2 = -x + 2 * n - d
        
        if (y >= y1) and (y <= y2):
            return True
        return False    

def main():
    n, d = [int(elem) for elem in input().split()]
    
    m = int(input())
    
    ans = []
    
    k1 = 1
    b1 = -d
    
    k2 = -1
    b2 = 2*d
    
    for i in range(m):
        x, y = [int(elem) for elem in input().split()]
        
        if (n - d >= d):
            if (solve1(x, y, d, n)):
                ans.append("YES")
            else:
                ans.append("NO")
        else:
            if (solve2(x, y, d, n)):
                ans.append("YES")
            else:
                ans.append("NO")
            
            
    for st in ans:
        print(st)
if __name__ == "__main__":
    main()