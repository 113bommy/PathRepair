[n, d] = [int(x) for x in input().split()]
L = []
for i in range(d):
    s = input()
    if '0' not in s: L.append(i)
L.append(d)
print(max([L[i] - L[i-1] - 1 for i in range(1, len(L))]) if len(L) != 1 else d)
