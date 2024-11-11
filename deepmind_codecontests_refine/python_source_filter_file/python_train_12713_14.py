n, k= input().split()
n = int(n)
k = int(k)
red = 2 * n
green = 5 * n
blue = 8 * n
r1 = red % k
r2 = green % k
r3 = blue % k
w1 = k - r1
w2 = k - r2
w3 = k - r3
if r1 == 0:
    w1 = 0
if r2 == 0:
    w2 = 0
if r3 == 0:
    w3 = 0
red_new = red + w1
green_new = green + w2
blue_new = blue + w3
p1 = red_new / k
p2 = green_new / k
p3 = blue_new / k
total = p1 + p2 + p3
print(total)






