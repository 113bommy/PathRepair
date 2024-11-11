n = int(input())
lst = [int(j) for j in input().split()]
inversions = list()
for i in range(1, n):
    for j in range(i):
        if lst[i] < lst[j]:
            inversions.append((i, -lst[j], -j))
inversions.sort(reverse=True)
res = list(range(len(inversions)))
if res:
    print(len(res))
    for elem in res:
        v, _, u = inversions[elem]
        u = - u
        print(u + 1, v + 1)
else:
    print('wut')



