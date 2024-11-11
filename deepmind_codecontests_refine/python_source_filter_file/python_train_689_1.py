n, d = [int(x) for x in input().split()]
multiset = [int(x) for x in input().split()]

multiset.sort()

max_inside = -1
for i in range(n-1):
    for j in range(i+1, n):
        if multiset[j] - multiset[i] <= d and j-i > max_inside:
            max_inside = j-i+1
print(n-max_inside)