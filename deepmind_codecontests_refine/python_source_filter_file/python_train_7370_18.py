(n,), *z = [[*map(int, o.split())] for o in open(0)]
if n == 1:
    print(1)
    exit()
from itertools import*
from collections import*
print(n - Counter((z[i][0] - z[j][0], z[i][1] - z[j][1]) for i, j in combinations(range(n), 2)).most_common()[0][1])