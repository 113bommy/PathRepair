import sys

I = 0
L = 1
R = 2
P = 3
B = 4
D = 5
H = 6

def getroot(A, id):
    if A[id][P] > -1:
        return getroot(A,A[id][P])
    return A[id][I]

def preorder(N,id,A):
    if id < 0:
        return
    A.append(id)
    preorder(N,N[id][L],A)
    preorder(N,N[id][R],A)

def inorder(N,id,A):
    if id < 0:
        return
    inorder(N,N[id][L],A)
    A.append(id)
    inorder(N,N[id][R],A)

def postorder(N,id,A):
    if id < 0:
        return
    postorder(N,N[id][L],A)
    postorder(N,N[id][R],A)
    A.append(id)


def main():

    """ ????????? """
    num = int(input().strip())
    istr = sys.stdin.read()
    nlist = list(istr.splitlines())
    
    nodes = [[i, -1, -1, -1, -1, 0, 0] for i in range(num)]

    for nstr in nlist:
        i = list(map(int,nstr.split()))
        n = nodes[i[I]]
        n[I] = i[I]
        if i[L] > -1:
            n[L] = i[L]
            nodes[n[L]][P] = i[I]
            nodes[n[L]][B] = i[R]
        if i[R] > -1:
            n[R] = i[R]
            nodes[n[R]][P] = i[I]
            nodes[n[R]][B] = i[L]
#        print("set n:{} {} {}".format(n[I],n,i))

    r = getroot(nodes, 0)
#    setd(nodes,r, 0)

    pre = [""]
    ino = [""]
    pos = [""]

    preorder(nodes,r,pre)
    inorder(nodes,r,ino)
    postorder(nodes,r,pos)

    print("Preorder")
    print(" ".join(map(str,pre)))
    print("Inorder")
    print(" ".join(map(str,ino)))
    print("Postorder")
    print(" ".join(map(str,pos)))
if __name__ == '__main__':
    main()