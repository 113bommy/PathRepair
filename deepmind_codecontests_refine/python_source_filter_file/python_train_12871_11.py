vertices, edges = [int(c) for c in input().split(" ")]

primelist = [2, 3, 5, 7]
for i in range(11, (10**5) + 10000, 2):
    temp = True
    for p in primelist:
        if i % p == 0:
            temp = False
            break
        elif i < p*p:
            break
    if temp:
        primelist.append(i)

mst_len = 0
for p in primelist:
    if p > vertices:
        mst_len = p
        break

'''
print(2, mst_len)
print(1, 2, mst_len - 2 - 2*(vertices-3))
for i in range(3, vertices+1):
    print(1, i, 2)

it = edges - (vertices-1)
for i in range(2, vertices+1):
    if it <= 0:
        break
    for j in range(i+1, vertices+1):
        if it <= 0:
            break
        print(i, j, 10**8 - 1)
        it -= 1
'''

print(mst_len, mst_len)
for i in range(2, vertices - 1):
    print(i-1, i, 1)
print(vertices-1, vertices, mst_len - (vertices - 2))

it = edges - (vertices-1)
for i in range(1, vertices+1):
    if it <= 0:
        break
    for j in range(i+2, vertices+1):
        if it <= 0:
            break
        print(i, j, 10**9 - 1)
        it -= 1
