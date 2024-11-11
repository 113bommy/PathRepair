import math
n = int(input())
strng = input()
tmp_alph = 'qwertyuiopasdfghjklzxcvbnm'
alph = {}
count = 0
for elem in tmp_alph:
        alph[elem] = 0
if n > 26:
    print(-1)
else:
    for elem in strng:
        alph[elem] += 1
    for elem in alph.values():
        if elem > 1:
            count += (elem - 1)
    print(count)
