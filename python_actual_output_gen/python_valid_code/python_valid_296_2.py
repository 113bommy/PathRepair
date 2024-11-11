line = input().split()
n = int(line[0])
t = int(line[1])

line = input().split()

for i in range(t):
    t = t - (86400 - int(line[i]))
    if t < 1:
        break

print(i + 1)
