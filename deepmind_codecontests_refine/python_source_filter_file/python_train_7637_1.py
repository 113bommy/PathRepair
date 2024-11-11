n = int(input())
a = []
for i in range(n):
    a.append(int(input()))

time = 0
h = 0
for i in range(n):
    time += a[i] - h + 1
    h += a[i] - h
    if i<n-1: 
        if a[i+1] >= h:
            time += 1
        else:
            time += h - a[i+1] + 1
            h -= a[i+1]
print(time)