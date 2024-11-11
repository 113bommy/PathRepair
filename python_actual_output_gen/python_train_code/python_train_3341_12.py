import sys

def check(a, d, v):
    min_dist = 40000000

    for i in a:
        min_dist = min(min_dist, abs(i - v))
    
    if min_dist == d:
        return True
    
    return False
 
if __name__ == "__main__":
    n, d = (int(x) for x in sys.stdin.readline().split())
    a = [int(x) for x in sys.stdin.readline().split()]
    ans = set()
    
    for v in a:
        if check(a, d, v - d):
        	ans.add(v - d)
        
        if check(a, d, v + d):
        	ans.add(v + d)
        
    print(len(ans))
