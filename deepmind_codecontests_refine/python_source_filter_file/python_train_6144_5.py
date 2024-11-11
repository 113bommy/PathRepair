class Tree:
    __slots__ = ['id', 'p', 'left', 'right', "type"]
    def __init__(self, id):
        self.id = id
        self.p = -1
        self.left = -1
        self.right = -1
        self.type = "leaf"
    def __str__(self):
        return f"node {self.id}: parent = {self.p}, left = {self.left}, right = {self.right}, type = {self.type}"
n = int(input())
tree = tuple(Tree(i) for i in range(n))
for _ in range(n):
    id, l, r = map(int, input().split())
    if l != -1:
        tree[id].left = l
        tree[l].p = id
    if r != -1:
        tree[id].right = r
        tree[r].p = id
root = 0
while tree[root].p != -1:
    root = tree[root].p
def preorder_tree_walk(id):
    print(f" {tree[id].id}", end="")
    if tree[id].left != -1:
        preorder_tree_walk(tree[id].left)
    if tree[id].right != -1:
        preorder_tree_walk(tree[id].right)
def inorder_tree_walk(id):
    if tree[id].left != -1:
        inorder_tree_walk(tree[id].left)
    print(f" {tree[id].id}", end="")
    if tree[id].right != -1:
        inorder_tree_walk(tree[id].right)
def postorder_tree_walk(id):
    if tree[id].left != -1:
        postorder_tree_walk(tree[id].left)
    if tree[id].right != -1:
        postorder_tree_walk(tree[id].right)
    print(f" {tree[id].id}", end="")
print("Preorder")
preorder_tree_walk(root)
print("\nInorder")
inorder_tree_walk(root)
print("\nPostorder")
postorder_tree_walk(root)

