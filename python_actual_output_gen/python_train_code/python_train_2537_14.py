temp = [int(x) for x in input().split()]
n = temp[0]
b = temp[1]
d = temp[2]
a = [int(x) for x in input().split()]
B = 0
counter = 0
for i in range(n):
    if a[i] <= b:
        B += a[i]
        if B > b:
            if B > d:
                counter += 1
            B = 0
print(counter)
