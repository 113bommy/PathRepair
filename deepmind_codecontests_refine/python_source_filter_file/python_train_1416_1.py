s = input()
a = s.split(':')
a = [int(a[0]), int(a[1])]
if a[0] == 12:
    a[0] = 0
m = (a[1]*6)
h = (a[0]*30) + (a[1]/2)
if h%1 == 0:
    h = int(h)
print(h, m)