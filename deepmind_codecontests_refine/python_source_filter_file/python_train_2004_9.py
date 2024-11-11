from collections import deque

def solve(n,m,a,b):
    if n*a != m*b:
        print("NO")
        return
    
    print("YES")
    row = [1]*a + [0]*(m-a)
    row = deque(row)
    for _ in range(m):
        print("".join(str(x) for x in row))
        row.rotate(a)
    return

for nt in range(int(input())):
    n,m,a,b = map(int,input().split())
    solve(n,m,a,b)
