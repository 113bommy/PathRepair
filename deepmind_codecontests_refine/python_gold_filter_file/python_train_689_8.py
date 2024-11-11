n, d = [int(x) for x in input().split()]
multiset = [int(x) for x in input().split()]

multiset.sort()

max_inside = -1
for i in range(n):
    for j in range(n-1, i-1, -1):
        if multiset[j] - multiset[i] <= d and j-i+1 > max_inside:
            max_inside = j-i+1
            break
print(n-max_inside)
