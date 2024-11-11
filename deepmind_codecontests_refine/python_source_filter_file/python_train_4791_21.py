n = int(input())
H = list(map(int, input().split(' ')))

for i in range(n):
    node = i+1
    key = H[i]
    parent = H[int(node/2)] if node != 1 else None
    left = H[node*2-1] if node*2 <= n else None
    right = H[node*2] if node*2+1 <= n else None
    print('node %d: key = %d,'%(node, key), end='')
    if parent != None: print(' parent key = %d,'%parent, end='')
    if left != None: print(' left key = %d,'%left, end='')
    if right != None: print(' right key = %d,'%right, end='')
    print('')
