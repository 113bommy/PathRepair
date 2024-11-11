# cook your code here
def solve():
    x, y, p, q = map(int, input().split())
    
    if p == 0:
        if x == 0:
            print(0)
            return
        else:
            print(-1)
            return
        
    if p == q:
        if x == y:
            print(0)
            return
        else:
            print(-1)
            return
        
    var1 = ( p + x - 1 ) // p;
    var2 = ((y - x) + (q - p) - 1) // (q - p);
    max1 = max(var1, var2);
    solution = (max1 * q) - y;
    
    print(solution)
    return


def main():
    n = int(input())
    for i in range (n):
        solve()
        
main()