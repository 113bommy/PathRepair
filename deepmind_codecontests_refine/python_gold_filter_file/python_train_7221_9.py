mat = []
i1 = 0
j1 = 0

for i in range(5):
    mat.append([int(j) for j in input().split()])
    for j in range(5):
        if mat [i] [j] == 1:
            i1 = i
            j1 = j
print(abs(2-i1)+abs(2-j1))