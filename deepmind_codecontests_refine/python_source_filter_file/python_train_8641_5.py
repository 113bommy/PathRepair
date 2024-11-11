class Node:
    def __init__(self, parent=-1, left=-1, right=-1):
        self.parent = parent
        self.left = left
        self.right = right


n = int(input())
binary_tree = [Node() for i in range(n)]
h, d = [0 for j in range(n)], [0 for k in range(n)]


def set_height(u):
    h1 = h2 = 0
    if binary_tree[u].right != -1:
        h1 = set_height(binary_tree[u].right) + 1
    if binary_tree[u].left != -1:
        h2 = set_height(binary_tree[u].left) + 1

    h[u] = max(h1, h2)
    return h[u]


def set_depth(u, dep):
    d[u] = dep
    if binary_tree[u].right != -1:
        set_depth(binary_tree[u].right, dep+1)
    if binary_tree[u].left != -1:
        set_depth(binary_tree[u].left, dep+1)

    return d[u]


def set_sibling(u):
    if binary_tree[binary_tree[u].parent].left != u:
        return binary_tree[binary_tree[u].parent].left
    else:
        return binary_tree[binary_tree[u].parent].right


def set_degree(u):
    cnt = 0
    if binary_tree[u].left != -1:
        cnt += 1
    if binary_tree[u].right != -1:
        cnt += 1
    return cnt


def set_type(u):
    if binary_tree[u].parent == -1:
        return "root"
    elif binary_tree[u].left == -1 and binary_tree[u].right == -1:
        return "leaf"
    else:
        return "internal node"


def main():
    for i in range(n):
        idx, left, right = map(int, input().split())
        binary_tree[idx].left = left
        binary_tree[idx].right = right
        if left != -1:
            binary_tree[left].parent = idx
        if right != -1:
            binary_tree[right].parent = idx

    # 根の探索
    root_idx = 0
    for i in range(n):
        if binary_tree[i].parent == -1:
            root_idx = i
            break

    # 各ノードの高さを求める
    set_height(root_idx)

    # 各ノードの深さを求める
    set_depth(0, 0)

    for i in range(n):
        print("node {}: parent = {}, sibling = {}, degree = {}, depth = {}, "
              "height = {}, {}".format(i, binary_tree[i].parent,
                set_sibling(i), set_degree(i), d[i], h[i], set_type(i)))


if __name__ == '__main__':
    main()

