n, k = [int(x) for x in input().split()]
h = [int(x) for x in input().split()]

# calculate initial sum of heights
s = 0
for i in range(k):
    s += h[i]

mn = s
j = 1

for i in range(n-k):
    s -= h[i]
    s += h[k+i]

    if s < mn:
        mn = s
        j = i+1+1

print(j)

