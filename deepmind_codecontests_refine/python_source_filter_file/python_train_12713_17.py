n, k = input().split()
r = int(n) * 2
g = int(n) * 5
b = int(n) * 8
#red
if (r % int(k)) == 0:
    x = r / int(k)
else:
    x1 = r // int(k)
    x = x1 +1
#green
if (g % int(k)) == 0:
    y = g / int(k)
else:
    y1 = g // int(k)
    y = y1 + 1
#blue
if (b % int(k)) == 0:
    z = b / int(k)
else:
    z1 = b // int(k)
    z = z1 + 1
sum = x + y +z
print(sum)