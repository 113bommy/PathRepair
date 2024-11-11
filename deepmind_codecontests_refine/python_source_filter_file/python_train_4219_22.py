n = int(input())
fsize = int(input())
p = []
sum, counter = 0, 0
for i in range (0, n):
    p.append(int(input()))
p.sort()
for i in range (n-1, 0, -1):
    sum += p[i]
    counter += 1
    if sum>=fsize:
        print(counter)
        exit()