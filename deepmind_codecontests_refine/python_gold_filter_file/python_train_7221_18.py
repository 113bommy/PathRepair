a = []
ai =0
aj = 0
count = 0
count2 = 0
for i in range(5):
    a.append([int(j) for j in input().split()])
for i in range(5):
    for j in range (5):
        if a[i][j] == 1:
            ai = i
            aj = j
if ai < 2:
    count = 2-ai
if ai>2:
    count = ai-2
if ai == 2:
    count = 0
if aj < 2:
    count2 = 2-aj
if aj >2:
    count2 = aj-2
if aj == 2:
    count2 = 0
print(count + count2)

