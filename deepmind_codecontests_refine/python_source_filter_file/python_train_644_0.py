import sys
input = sys.stdin.readline
def segtree(i,l,r,arr):
    if l==r:
        tree[i]=arr[l]
        return tree[i]
    m=(l+r)//2
    tree[i]=min(segtree(2*i+1,l,m,arr),segtree(2*i+2,m+1,r,arr))
    return tree[i]
def update(i,l,r,num,ind):
    if ind<l or ind>r:
        return
    elif l==r:
        tree[i]=num
        return
    m=(l+r)//2
    update(2*i+1,l,m,num,ind)
    update(2*i+2,m+1,r,num,ind)
    tree[i]=min(tree[2*i+1],tree[2*i+2])
    return
def search(i,l,r,num):
    if l==r:
        return l
    m=(l+r)//2
    if tree[2*i+1]==num:
        return search(2*i+1,l,m,num)
    else:
        return search(2*i+2,m+1,r,num)
q,x=map(int,input().split())
arr=[0]*x
i=0
while 2**i<x:
    i=i+1
tree=[0]*(2**(i+1)-1)
segtree(0,0,x-1,arr)
for _ in range(q):
    y=int(input())
    arr[y%x]+=1
    update(0,0,x-1,arr[y%x],y%x)
    i=search(0,0,x-1,tree[0])
    if tree[0]==0:
        print(i)
    else:
        if i==0:
            sys.stdout.write(str(x*(tree[0])) + "\n")
        else:
            sys.stdout.write(str(x*(tree[0])+1) + "\n")