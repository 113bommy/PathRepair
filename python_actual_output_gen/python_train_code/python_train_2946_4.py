import sys
f = sys.stdin
#f = open("input.txt", "r")
a = f.readline()
print(a)
prev = a[0]
count = 0
k = 0
for i in a[1:]:
    if i != prev:
        count += 1
        k = 0
    elif i == prev and k < 4:
        k += 1
    elif i == prev and k == 4:
        count += 1
        k = 0
    prev = i
print(count+1)