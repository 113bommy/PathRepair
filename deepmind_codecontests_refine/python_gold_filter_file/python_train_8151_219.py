a = input().split(" ")
a[0] = int(a[0])
a[1] = int(a[1])
a[2] = int(a[2])
a[3] = int(a[3])
a[4] = int(a[4])
a[5] = int(a[5])
a[6] = int(a[6])
a[7] = int(a[7])
b = a[1] * a[2] // a[6]
c = a[3] * a[4]
d = a[5] // a[7]
l = min(b , c , d)
print(l // a[0])