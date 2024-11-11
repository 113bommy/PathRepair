n, m = map(int,input().split())
task = list(map(int,input().split()))

t = 0
curr = 1

for i in range(m):
    if task[i] < curr :
        t += (n - curr) + task[i]
        
    else:
        t += task[i] - curr
    curr = task[i]
print(t)