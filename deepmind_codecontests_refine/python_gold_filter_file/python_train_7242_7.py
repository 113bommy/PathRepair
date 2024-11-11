# Bulbasaur


string = input()
#B = 0
#u = 1
# l = 2
# b = 3
# a = 4
# s = 5
# r = 6
ind = [0, 0, 0, 0, 0, 0, 0]
# B =
for i in string:
    if i == 'B':
        ind[0] = ind[0] + 1
    elif i == 'u':
        ind[1] = ind[1] + 1
    elif i == 'l':
        ind[2] = ind[2] + 1
    elif i == 'b':
        ind[3] = ind[3] + 1
    elif i == 'a':
        ind[4] = ind[4] + 1
    elif i == 's':
        ind[5] += 1
    elif i == 'r':
        ind[6] += 1

min = ind[0]
for i in (2,3,5,6):
    if ind[i] < min:
        min = ind[i]

if ind[1] < min * 2:
    min = (ind[1]//2)
if ind[4] < min * 2:
    min = (ind[4]//2)
print(min)