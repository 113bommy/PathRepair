n = int(input())
rows = []
columns = []
for x in range(n):
    string = input()
    numbers = string.split()
    rows.append(int(numbers[0]))
    columns.append(int(numbers[1]))
vx = [0 for x in range(1999)]
vy = [0 for x in range(1999)] 
for x in range(n):
    r = rows[x]
    c = columns[x]
    vx[r - c] += 1
    vy[c - r] += 1
a = sum(list(map(lambda x: x * (x - 1) // 2, vx + vy)))
print(a)