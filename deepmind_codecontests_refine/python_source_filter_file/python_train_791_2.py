from itertools import permutations

n = int(input())
m = 0
lis = [0 for _ in range(1000)]
lis[0] = 1
a = []
for _ in range(n):
    s = input().split()
    for i in s:
        lis[int(i)] = 1
    a.append(s)

if n == 3:
    for i in a[0]:
        for j in a[1]:
            for k in a[2]:
                l = permutations([i, j, k], 3)
                for item in l:
                    lis[int(item[0]+item[1]+item[2])] = 1
                l = permutations([i, j, k], 2)
                for item in l:
                    lis[int(item[0]+item[1])] = 1
elif n == 2:
    for i in a[0]:
        for j in a[1]:
                l = permutations([i, j], 3)
                for item in l:
                    lis[int(item[0]+item[1])] = 1  
ind = lis.index(0)-1

print(ind)
