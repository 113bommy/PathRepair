n = int(input())
masb = []
masd = []
for i in range(n):
    z1, z2 = map(int, input().split())
    masb.append(z1)
    masd.append(z2)
masb.sort()
masd.sort()
j = 0
k = 0
y = 0
mx = [0, 0]
for i in range(len(masb)):
    y = masb[i]
    k += 1
    while y >= masd[j]:
        k -= 1
        j += 1
    if k > mx[0]:
        mx = [y, k]
print(*mx)
