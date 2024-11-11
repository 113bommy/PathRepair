n = int(input())
c = input()
l = 0
r = 0
for i in range(len(c)):
    if i == 'L':
        l += 1
    elif i == 'R':
        r += 1
print(l + r + 1)