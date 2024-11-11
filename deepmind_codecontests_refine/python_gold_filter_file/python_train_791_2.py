n = int(input())
cubes = [[int(elem) for elem in input().strip().split(' ')] for i in range(n)]
def f(cubes):
    dic = {}
    pos = {}
    for i in range(n):
        for j, elem in enumerate(cubes[i]):
            if elem in dic:
                dic[elem] += 1 
                pos[elem].add(i)
            else: 
                dic[elem] = 1
                pos[elem] = set((i, ))
    for i in range(1, 10):
        if not i in dic:
            return i - 1
    if not 0 in dic:
        return 9
    for i in range(1, 10):
        for j in range(10):
            # print(i, j)
            # print(pos[i].union(pos[j]))
            # print(pos[i], pos[j])
            if len(pos[i].union(pos[j])) == 1:
                return 10 * i + j - 1

print(f(cubes))

