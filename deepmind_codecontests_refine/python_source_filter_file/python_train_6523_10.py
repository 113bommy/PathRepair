f = input().split(" ")
n = int(f[0])
k = int(f[1])
a = input().split(" ")
for i in range(0, n):
    a[i] = int(a[i])
a_updated = sorted(a)
if n <= k:
    print(a_updated[-1]+1)
else:
    if k != 0 and len(a_updated) > 1:
        if a_updated[k-1] == a_updated[k]:
            print(-1)
        else:
            print(a_updated[k-1])
    elif k != 0 and len(a_updated) == 1:
        if a_updated[0] != 1:
            print(a_updated[0])
        else:
            print(-1)
    elif k == 0:
        if a_updated[0] != 1:
            print(a_updated[0]-1)
        else:
            print(-1)
    else:
        print(a_updated[k-1])
