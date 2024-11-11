a1 = int(input())
a2 = int(input())
a3 = int(input())
a4 = int(input())
d = int(input())
p = 0
for i in range(d) :
    if i%a1 == 0 or i%a2 == 0 or i%a3 == 0 or i%a4 == 0 :
        p += 1
print(p)