n,l = [int(x) for x in input().strip().split()]
A = [int(x) for x in input().strip().split()]
B = []
for x in A:
    if l%x == 0:
        B.append(x)
print(l/max(B))