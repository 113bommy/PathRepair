def tmp_sort(n):
    return n[0]
    

t = int(input())
for i in range(t):
    num_caves = int(input())
    monsters = []
    strongest = []
    for j in range(num_caves):
        lst = [int(x) for x in input().split()]
        monsters.append(lst[1:])
    for cave in monsters:
        strong = 0
        for j in range(len(cave)):
            cave[j] -= j
            if cave[j] > strong:
                strong = cave[j]
        strongest.append((strong, len(cave)))
    strongest.sort(key=tmp_sort)
    min_start = strongest[0][0]+1
    current = min_start
    for strong in strongest:
        if current <= strong[0]:
            tmp = strong[0] + 1 - current
            min_start += tmp
            current += tmp
        current += strong[1]
    print(min_start)
    
    