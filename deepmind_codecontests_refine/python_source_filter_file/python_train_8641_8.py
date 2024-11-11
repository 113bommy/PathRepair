N = int(input())


binary_tree = [{"parent": -1, "sibling": -1} for _ in range(N)]
for _ in range(N):
    node_input = input()
    id, left, right = map(int, node_input.split())

    binary_tree[id]["left"] = left
    binary_tree[id]["right"] = right

    if left != -1:
        binary_tree[left]["parent"] = id
    if right != -1:
        binary_tree[right]["parent"] = id


def set_depth(id, depth):
    if id == -1:
        return

    D[id] = depth
    set_depth(binary_tree[id]["left"], depth+1)
    set_depth(binary_tree[id]["right"], depth+1)

def set_height(id):
    h1, h2 = 0, 0
    if binary_tree[id]["left"] != -1:
        h1 = set_height(binary_tree[id]["left"]) + 1
    if binary_tree[id]["right"] != -1:
        h1 = set_height(binary_tree[id]["right"]) + 1
    H[id] = max(h1, h2)
    return H[id]


D = [0 for i in range(N)]
H = [0 for i in range(N)]
for id in range(N):
    if binary_tree[id]["parent"] == -1:
        set_depth(id, 0)
        set_height(id)


def get_sibling(id):
    parent_id = node["parent"]
    if parent_id == -1:
        return -1
    if binary_tree[parent_id]["left"] != id:
        return binary_tree[parent_id]["left"]
    else:
        return binary_tree[parent_id]["right"]

def get_degree(node):
    degree = 0
    if node["left"] != -1:
        degree += 1
    if node["right"] != -1:
        degree += 1
    return degree

def get_type(node, dgree):
    if node["parent"] == -1:
        return "root"
    if degree == 0:
        return "leaf"
    return "internal node"

for id in range(N):
    node = binary_tree[id]
    parent_id = node["parent"]
    sibling_id = get_sibling(id)
    degree = get_degree(node)
    node_type = get_type(node, degree)
    print("node {}: parent = {}, sibling = {}, degree = {}, depth = {}, height = {}, {}".format(id, parent_id, sibling_id, degree, D[id], H[id], node_type))
