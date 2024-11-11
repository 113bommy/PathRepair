n = int(input())
left = [None for i in range(n)]
right = [None for i in range(n)]
root = sum(range(n)) - n - 1

for i in range(n):
    i, l, r = map(int, input().split())
    left[i] = l
    right[i] = r
    root -= (l + r)

def Preorder(i):
    if (i == -1):
        return
    print(" {}".format(i), end = "")
    Preorder(left[i])
    Preorder(right[i])
      
def Inorder(i):
    if (i == -1):
        return
    Inorder(left[i])
    print(" {}".format(i), end = "")
    Inorder(right[i])
      
def Postorder(i):
    if (i == -1):
        return
    Postorder(left[i])
    Postorder(right[i])
    print(" {}".format(i), end = "")

print("Preorder")
Preorder(root)
print()
  
print("Inorder")
Inorder(root)
print()
  
print("Postorder")
Postorder(root)
print()