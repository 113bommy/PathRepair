from collections import defaultdict

n, m = [int (i) for i in input().split(" ")]
can = defaultdict(int)
for i in range(m):
    arr = [int (i) for i in input().split(" ")]
    t = 0
    for j in range(n):
        if arr[j] > arr[t]:
            t = j
    can[j] += 1
    
t = 0
for i in range (n):
    if can[i] > can[t]:
        t = i
        
print (t)