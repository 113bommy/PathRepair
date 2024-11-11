n = int(input())
tree = {1: []}

for node in range(n - 1):
    c = int(input())
    tree[c] += [node+2]
    tree[node+2] = []

for key, value in tree.items():
    leafs = 0
    if not value:
        continue
    for node in value:
        if not tree[node]:
            leafs += 1
    if leafs < 3:
        print('No')
        break
else:
    print('Yes')
