import itertools
n = int(input())
cubes = []
for _ in range(n):
    cubes.append(list(map(int, input().split())))

for i in range(1000):
    s = str(i)
    perms = list(itertools.permutations(cubes))
    hasPerm = False
    for perm in perms:
        good = True
        for n in range(len(s)):
            if (int(s[n]) not in perm[n]):
                good = False
        if good:
            hasPerm = True
            break
    if hasPerm == False:
        print(i-1)
        exit()


