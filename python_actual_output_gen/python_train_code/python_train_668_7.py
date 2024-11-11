t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    sum_a = 0
    
    for i in range(n):
        sum_a += a[i]
    
    if sum_a == m:
        print("YEES")
    else:
        print("NO")