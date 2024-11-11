n, m = input().split()
n, m = int(n), int(m)

lst = input().split()
for i in range(m):
    lst[i] = int(lst[i])
    
time = 0

for i in range(m):
    if time == 0:
        time = lst[i] - 1
    else:
        if lst[i] < lst[i-1]:
            time = time + (n - lst[i-1] + 1) + (lst[i] - 1)
        else:
            time = time + (lst[i] - lst[i -1])
            
print(time)