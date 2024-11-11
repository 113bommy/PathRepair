#http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_C&lang=jp
import time
def preorder(binary_tree, target_index, result):

    result.append(target_index)
    
    left = binary_tree[target_index]["left"]
    right = binary_tree[target_index]["right"]
    if not left == -1:
        preorder(binary_tree, left, result)
    if not right == -1:
        preorder(binary_tree, right, result)

def inorder(binary_tree, target_index, result):
    
    left = binary_tree[target_index]["left"]
    right = binary_tree[target_index]["right"]
    
    if not left == -1:
        inorder(binary_tree, left, result)
    
    result.append(target_index)
    
    if not right == -1:
        inorder(binary_tree, right, result)

def postorder(binary_tree, target_index, result):
    
    left = binary_tree[target_index]["left"]
    right = binary_tree[target_index]["right"]
    
    if not left == -1:
        postorder(binary_tree, left, result)
    if not right == -1:
        postorder(binary_tree, right, result)

    result.append(target_index)
    
def make_binary_tree(node_data, node_num):
    binary_tree = [{"left":-1, "right":-1} for a in range(node_num)]
    root_index = sum([i for i in range(node_num)])

    for node in node_data:
        binary_tree[node[0]]["left"] =  node[1]
        binary_tree[node[0]]["right"] =  node[2]

        if not node[1] == -1:
            root_index -= node[1]
        if not node[2] == -1:
            root_index -= node[2]

    return root_index, binary_tree

def main():
    node_num = int(input())
    node_data = [[int(a) for a in input().split()] for i in range(node_num)]
    root_index, binary_tree = make_binary_tree(node_data, node_num)
    
    preorder_list = []
    preorder(binary_tree, root_index, preorder_list)
    print("Preorder\n", *preorder_list)
    inorder_list = []
    inorder(binary_tree, root_index, inorder_list)
    print("Inorder\n", *inorder_list)
    postorder_list = []
    postorder(binary_tree, root_index, postorder_list)
    print("Postorder\n", *postorder_list)
if __name__ == "__main__":
    main()
    