t = int(input())
a = []
for i in range(t):
    a.append(int(input()))

largest = 0
for i in range(t):
    if a[i] != -1:
        x = a[i]
        counter = 1
        while x != -1:
            x = a[x-1]
            counter += 1
        if counter > largest:
            largest = counter
print(largest)
