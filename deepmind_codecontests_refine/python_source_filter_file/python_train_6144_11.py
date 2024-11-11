n = int(input())
tree = [0] * n
root = set(range(n))
for i in range(n):
    node_id, left, right = map(int, input().split())
    tree[node_id] = (left, right)
    root -= {left, right}
root_node = root.pop()


def preorder(i):
    if i == -1:
        return
    (left, right) = tree[i]
    yield i
    yield from preorder(left)
    yield from preorder(right)


def inorder(i):
    if i == -1:
        return
    (left, right) = tree[i]
    yield from inorder(left)
    yield i
    yield from inorder(right)


def postorder(i):
    if i == -1:
        return
    (left, right) = tree[i]
    yield from postorder(left)
    yield from postorder(right)
    yield i

print("preorder\n ", end="")
print(*preorder(root_node))
print("inorder\n ", end="")
print(*inorder(root_node))
print("postorder\n ", end="")
print(*postorder(root_node))