n, m = tuple(map(int, input().split()))
count = 0
x = 2 * n
y = 3 * n
z = 8 * n
if x > m and x % m != 0:
   count += x // m + 1
elif x < m:
   count += 1
else:
   count += m // x

if y > m and y % m != 0:
   count += y // m + 1
elif y < m:
   count += 1
else:
   count += m // y

if z > m and z % m != 0:
   count += z // m + 1
elif z < m:
   count += 1
else:
   count += m // z
print(count)
