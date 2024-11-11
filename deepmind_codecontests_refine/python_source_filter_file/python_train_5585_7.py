pairs= [int(s) for s in input().split(" ")]
n = int(pairs[0])
U = int(pairs[1])
levels = [int(s) for s in input().split(" ")]

levels.sort()

def find_nearest(levels,start,finish, max_level):
    if start > finish:
        return -1
    if start > (n-1):
        return -1

    if levels[start] > max_level:
        return -1
    if levels[finish] <= max_level:
        return finish
    if (finish - start) < 2:
        return start

    mid = (start + finish)//2
    if levels[mid] > max_level:
        return find_nearest(levels, start, mid, max_level)
    else:
        return find_nearest(levels, mid + 1, finish, max_level)

coeff = -1

for j in range(1,n):
    i = j -1
    if coeff > (1 - (levels[j]-levels[i])/(levels[n-1] - levels[i])):
        continue
    k=find_nearest(levels, j+1, n-1, U + levels[i])
    if (k==-1):
        continue

    coeff = max(coeff, (1 - (levels[j]-levels[i])/(levels[k] - levels[i])))

print(coeff)