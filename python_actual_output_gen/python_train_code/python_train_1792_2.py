n = int(input())
a = [x for x in map(int, input().split())][:n]
m = min(a)
ind1 = a.index(m)
small = 100000
for i in range(ind1+1, len(a)):
    if a[i] is m:
        ind2 = i
        if small > (ind2 - ind1):
            small = ind2 - ind1
        ind1 = ind2

print(small)