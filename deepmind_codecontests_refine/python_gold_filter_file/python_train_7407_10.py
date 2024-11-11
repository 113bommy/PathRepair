
n = int(input())
list = 2000 * [-3]

for i in range (n):
    k = int(input())
    list[i] = k - 1


max = 0
for i in range (n):
    c = 0
    k = i
    while k >= 0:
        k = list[k]
        c += 1
    if c > max :
        max = c

print(max)