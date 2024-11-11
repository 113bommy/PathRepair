n, d = [int(x) for x in input().split()]
multiset = [int(x) for x in input().split()]

multiset.sort()

max_inside = -1
for i in range(n):
    for j in range(i, n):
        if multiset[j] - multiset[i] <= d and j-i+1 > max_inside:
            max_inside = j-i+1
print(n-max_inside)
