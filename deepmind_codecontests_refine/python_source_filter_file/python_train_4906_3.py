import sys

n = int(sys.stdin.readline().strip())
a = list(map(int, sys.stdin.readline().strip().split()))
if sum(a) < 2 * n - 2:
    print("NO")
else:
    nleaves = a.count(1)
    print("YES " + str(n-max([nleaves, 2])+1))
    print(n - 1)
    leaves =[]
    nonleaves = []
    multiplicity = []
    for i in range (0, n):
        if a[i] == 1:
            leaves.append(i)
        else:
            nonleaves.append(i)
            if len(multiplicity) < n:
                for j in range (0, a[i] - 1):
                    multiplicity.append(i)
    if leaves != []:
        v = leaves.pop(-1)
    else:
        v = nonleaves.pop(-1)
    for w in nonleaves:
        print(str(v + 1) + " " + str(w + 1))
        v = w
    for w in leaves:
        print(str(v + 1) + " " + str(w + 1))
        v = multiplicity.pop(-1)