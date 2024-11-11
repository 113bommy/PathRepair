import sys
input = lambda: sys.stdin.readline().rstrip()

def solve(n, m):
    L0 = []
    L1 = []
    num = [0 for j in range(m*n)]
    for i in range(n):
        grid = input()
        for j in range(m):
            if grid[j] == "*":
                c = i*n+j
                num[c] = 1
                if i >= 1 and 1 <= j < m-1:
                    L1.append(c)
                
    k = 1
    while L1:
        L0 = L1
        L1 = []
        for c in L0:
            if min(num[c], num[c-n], num[c-1], num[c+1]) == k:
                num[c] += 1
                L1.append(c)
        k += 1
                    
    return sum(num)
        
 
t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    print(solve(n, m))   
    