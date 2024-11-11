import sys
readline = sys.stdin.readline
 
def solve():
    N = int(readline())
    A = list(map(int, readline().split()))
    s = set()
    for i,a in enumerate(A):
        s.add(a+i)
    if len(s) == N:
        print('YES')
    else:
        print('NO')
    
T = int(readline())
for i in range(T):
    solve()