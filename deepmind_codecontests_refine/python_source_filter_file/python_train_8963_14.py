
import collections
import sys

elems = {}
l, r = -1, 1

queries = []

lines = sys.stdin.readlines()
q = int(lines[0].strip())
queries = lines[1:]
# q = int(input().strip())
for i in range(q):
    [queryType, index] = queries[i].strip().split()
    # [queryType, index] = input().strip().split()
    index = int(index)

    if queryType == 'L':
        elems[index] = l
        l -= 1
    elif queryType == 'R':
        elems[index] = r
        r += 1
    else:
        dex = elems[index]

        if dex > 0:
            ans1 = r-dex-1
            ans2 = dex-l-1
        else:
            ans1 = r-dex-1-1
            ans2 = dex-l-1

        print(min(ans1, ans2))

        # print(dex, l, r, len(elems))
