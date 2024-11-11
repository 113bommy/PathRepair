class Node():
    def __init__(self, key):
        self.key = key
        self.left = self.right = None
        
def insert(key):
    global root

    x = root
    y = None
    while x:x, y = x.left if key < x.key else x.right , x
    if y == None:root = Node(key)
    elif y.key < key:y.right = Node(key)
    else:y.left = Node(key)
        
        
def pre(node):
    if node == None:return
    print('',node.key, end = '');pre(node.left);pre(node.right)
    
def ino(node):
    if node == None:return
    ino(node.left);print('',node.key,end='');ino(node.right)


n = int(input())
root = None
for j in range(n):
    s, *i = input().split()
    if s[0] == 'i':insert(int(i[0]))
    else:
        ino(root);print();pre(root)
        
    
