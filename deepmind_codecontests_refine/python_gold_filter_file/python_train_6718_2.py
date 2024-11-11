F, I, T = map(int, input().split())
item = [0] * I
for i in range(F):
    s = input()
    for j in range(I):
        if s[j] == 'Y':
            item[j] += 1
print(sum([1 for x in item if x >= T]))
#kitten