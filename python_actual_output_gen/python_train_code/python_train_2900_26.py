# int(input())
# [int(s) for s in input().split()]
# input()
 
 
def solve():
    t = int(input())
    for i in range(t):
        n, x, a, b = [int(s) for s in input().split()]
        
        a, b = sorted([a,b])
        
        while b < n and x > 0:
            b += 1
            x -= 1
        
        while b > 1 and x > 0:
            a -= 1
            x -= 1
        
        print(abs(a-b))
    
 
 
 
if __name__ == "__main__":
    solve()