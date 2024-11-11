N = int(input())
tree = [None for _ in range(N)]
root = set(range(N))

for i in range(N):
    i, l, r = map(int,input().split())
    tree[i] = (l, r)
    root -= {l, r}

root_node = root.pop()

def preorder(i):
    if i == -1:
        return
    (l, r) = tree[i]
    print(" {}".format(i), end = "")
    preorder(l)
    preorder(r)
    
def inorder(i):
    if i == -1:
        return
    (l, r) = tree[i]
    inorder(l)
    print(" {}".format(i), end = "")
    inorder(r)
    
def postorder(i):
    if i == -1:
        return
    (l, r) = tree[i]
    inorder(l)
    inorder(r)
    print(" {}".format(i), end = "")
    
print('Preorder')
preorder(root_node)
print()

print('Inorder')
inorder(root_node)
print()

print('Postorder')
postorder(root_node)
print()