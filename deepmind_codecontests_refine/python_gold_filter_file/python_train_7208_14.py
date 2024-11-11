import math
t=int(input())

for _ in range(t):
    
    # n = int(input())
    n,m,k= map(int, input().split())
    # a = list(map(int, input().split()))
    
    # for i in range(n):
    #     print(a[i])
    print(int(min(m, n/k)-max(0, math.ceil((m-n/k)/(k-1)))))