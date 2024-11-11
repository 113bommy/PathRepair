import math

def solve():
    r, d = [int(x) for x in input().split(" ")]
    count = 0
    n = int(input())
    for i in range(n):
        xi, yi, ri = [int(x) for x in input().split(" ")]
        dis = int(math.sqrt(xi**2 + yi**2))
        if r-d+ri <= dis and dis+ri <= r:
            count = count + 1
    return count

if __name__=="__main__":
    print(solve())
        
    