import math
k = int(input())
if k == 0: 
    print(1, 1)
    print(0)
    exit()
a = 2 ** 17 - 1
print(3, 4)
t = int(math.log(k, 2)) + 1
t = 2 ** t
l = [[a, k, k, 0], [t, 0, k, 0], [a, a, a, k]]
for i in l: print(*i)