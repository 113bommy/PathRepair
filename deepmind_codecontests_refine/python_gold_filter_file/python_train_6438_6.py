# 10 5
# 1 2
# 1 3
# 1 4
# 8 10
# 1 8

n, m = map(int, input().split())

ends = []
starts = []
possible = False
for i in range(m):
    a, b = map(int, input().split())
    if a == 1:
        starts.append([a, b])
    elif b == n:
        ends.append([a, b])

starts.sort(key=lambda x: x[1])
ends.sort(key=lambda x: x[0])

if not (starts and ends):
    print("IMPOSSIBLE")
    import sys

    sys.exit()

i = 0
j = 0
while i != len(starts) and j != len(ends):
    to = starts[i][1]
    fr = ends[j][0]

    if to == fr:
        possible = True
        break

    if to < fr:
        i += 1
    elif fr < to:
        j += 1

while j != len(ends):
    fr = ends[j][0]
    if to == fr:
        possible = True
        break
    j += 1

while i != len(starts):
    to = starts[i][1]
    if to == fr:
        possible = True
        break
    i += 1

print("POSSIBLE") if possible else print("IMPOSSIBLE")
