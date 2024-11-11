a = int(input())
b = int(input())
c = int(input())
def solve(a,b,c):
    for i in range(min(a,b,c),0,-1):
        if i <= a and i*2 <= b and i*4 <= c:
            return i*7
    return 0
solve(a,b,c)
    
