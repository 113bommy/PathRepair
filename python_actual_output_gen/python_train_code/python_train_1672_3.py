n = int(input())
L = []
for j in range(n):
    T = [int(x) for x in input().split()]
    for i in T:
        if i == 3 or i == 1:
            break
    else:
        L.append(j)

print(len(L))
for i in L:
    print(i, end = ' ')