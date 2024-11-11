n = int(input())
cubes = [list(map(int, input().split())) for _ in range(n)] + [[], []]

for i in range(1,1000):
    for a,b,c in [(1,2,0), (1,0,2), (2,1,0), (2,0,1), (0,1,2), (0,2,1)]:
        if len(str(i)) == 1:
            if i in cubes[a]:
                break
        elif len(str(i)) == 2:
            if int(str(i)[0]) in cubes[a] and int(str(i)[1]) in cubes[b]:
                break
        else:
            if int(str(i)[0]) in cubes[a] and int(str(i)[1]) in cubes[b] and int(str(i)[2]) in cubes[c]:
                break
    else:
        print(max(i-1, 0))
        exit()
