h, w = map(int, input().split())
A= [[int(i) for i in input().split()] for i in range(h)]
B = []
count = 0

for i in range(h):
    for j in range(w - 1):
        if A[i][j] % 2 == 1:
            A[i][j + 1] += 1
            B.append([i + 1, j + 1, i + 1, j + 2])
            count += 1

for i in range(h - 1):
    if A[i][-1] % 2 == 1:
        A[i + 1][-1] += 1
        B.append([i + 1, w + 1, i + 2, w + 1])
        count += 1
        
print(count)
for i in B: 
    print(i[0], i[1], i[2], i[3])