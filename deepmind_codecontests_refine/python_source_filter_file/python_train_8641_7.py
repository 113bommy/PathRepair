#coding:UTF-8
def depth(leaf,A,d):
    for i in range(len(A)):
        if A[i][1]==leaf or A[i][2]==leaf:
            return depth(A[i][0],A,d+1)
    return d

def height(n,A,h):
    if n[1]!=-1 and n[2]!=-1:
        return max(height(A[n[1]],A,h+1),height(A[n[2]],A,h+1))
    return h

def BT(A,n):
    for i in range(n):
        p=0
        dep=0
        deg=0
        sib=0
        hei=0
        t=""
        if A[i][1]!=-1 and A[i][2]!=-1:
            deg=2
        elif A[i][1]!=-1 or A[i][2]!=-1:
            deg=1
        else:
            deg=0
        if A[i][1]==-1 and A[i][2]==-1 and n>1:
            t="leaf"
            deg=0
            dep=depth(A[i][0],A,dep)
            hei=height(A[i],A,hei)
            for j in range(len(A)):
                if A[i][0]==A[j][1]:
                    sib=A[j][2]
                    break
                elif A[i][0]==A[j][2]:
                    sib=A[j][1]
                    break
            for j in range(len(A)):
                if A[j][2]==A[i][0] or A[j][1]==A[i][0]:
                    p=A[j][0]
                    break
        else:
            hei=height(A[i],A,hei)
            for j in range(len(A)):
                if A[i][0]==A[j][1]:
                    sib=A[j][2]
                    break
                elif A[i][0]==A[j][2]:
                    sib=A[j][1]
                    break
            dep=depth(A[i][0],A,dep)
            if dep==0:
                sib=-1
                p=-1
                t="root"
            else:
                for j in range(len(A)):
                    if A[j][2]==A[i][0] or A[j][1]==A[i][0]:
                        p=A[j][0]
                        t="internal node"
                        break
        
        print("node "+str(A[i][0])+": parent = "+str(p)+", sibling = "+str(sib)+", degree = "+str(deg)+", depth = "+str(dep)+", height = "+str(hei)+", "+t)

if __name__=="__main__":
    n=int(input())
    A=[]
    for i in range(n):
        A.append(list(map(int,input().split(" "))))
    for i in range(n):
        minj=i
        for j in range(i,n):
            if A[j][0]<A[minj][0]:
                minj=j
        A[i],A[minj]=A[minj],A[i]
    BT(A,n)