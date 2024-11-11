i = input().split()
j = int(i[0])
k = int(i[1])
c = 0
while j <= k:
    j += j*3
    k += k*2
    c += 1
print(c)