s = input()
w,h,k = s.split(" ")
z = int(w)
h = int(h)
c = int(k)
p = 0
for i in range(c):
    p += (z+h-2)*2
    z-= 2
    h-= 2
print (p)