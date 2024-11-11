n, m = map(int, input().split())
a = []

for i in range(n):
    a += map(int, input().split())
            
t = 0

for i in range(1, m + 1):
    if i in a:
        t += 1
        
if t == m:
    print('YES')
else:
    print('NO')