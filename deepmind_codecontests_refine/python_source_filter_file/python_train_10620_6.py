def insert(r, n):
    if 0 == len(T):
        T[n] = [None, None]
    else:
        if n < r:
            left = T[r][0]
            if left == None:
                T[r][0] = n
                T[n] = [None, None]
            else:
                insert(left, n)
        if r < n:
            right = T[r][1]
            if right == None:
                T[r][1] = n
                T[n] = [None, None]
            else:
                insert(right, n)

def print_inorder(r):
    left = T[r][0]
    right = T[r][1]
    ans = ""
    if left != None:
        ans += print_inorder(left)
    ans += " {}".format(r)
    if right != None:
        ans += print_inorder(right)
    return ans

def print_preorder(r):
    left = T[r][0]
    right = T[r][1]
    ans = " {}".format(r)
    if left != None:
        ans += print_inorder(left)
    if right != None:
        ans += print_inorder(right)
    return ans




n = int(input())
T = {}

root = None
for i in range(n):
    inst = input()
    if inst[0] == 'i':
        num = int(inst[7:])
        if i == 0:
            root = num
        insert(root, num)
    elif inst[0] == 'p':
        print(print_inorder(root))
        print(print_preorder(root))