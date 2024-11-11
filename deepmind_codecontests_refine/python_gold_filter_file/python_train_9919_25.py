import sys
def solve(n1,n2):
    n1-=2
    if n1 <= 0:
        return 1
    else:
        if n1 % n2 == 0:
            return n1 // n2 + 1 
        else:
            return int((n1 / n2) + 1) + 1
    
for i in range(int(sys.stdin.readline())):
    a = list(map(int, sys.stdin.readline().split()))
    z1,z2 = a[0],a[1]
    print(solve(z1,z2))