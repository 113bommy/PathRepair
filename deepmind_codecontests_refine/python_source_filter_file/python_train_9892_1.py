def getPostorder(preorder, inorder):
    if not preorder:
        return []
    postorder = []
    root = preorder[0]
    rootIndex = inorder.index(root)

    postorder.extend(getPostorder(preorder[1:rootIndex + 1], inorder[:rootIndex]))
    postorder.extend(getPostorder(preorder[rootIndex + 1:], inorder[rootIndex + 1:]))
    postorder.append(root)

    return postorder 

if __name__ == '__main__':
    n = int(input())
    preorder = list(map(int, input().split()))
    inorder = list(map(int, input().split()))
    print(getPostorder(preorder, inorder))