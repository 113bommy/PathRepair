def solve():
    n,a,b = map(int,input().split())
    if b==1 or n==1:
        return True
    if a == 1:
        return (n-1)%b == 0
    ap = 1
    while ap < n:
        if (n-ap)%b == 0:
            return True
        ap *=a
    return False

for _ in range(int(input())):
    print("yes" if solve() else "no")
