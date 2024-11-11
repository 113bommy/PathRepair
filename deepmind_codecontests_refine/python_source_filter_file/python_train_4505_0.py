class BalancingTree:
    def __init__(self, n):
        self.N = n
        self.root = self.node(1<<n, 1<<n)

    def debug(self):
        def debug_info(nd_):
            return (nd_.value - 1, nd_.pivot , nd_.left.value - 1 if nd_.left else -1, nd_.right.value - 1 if nd_.right else -1,nd_.cnt)

        def debug_node(nd):
            re = []
            if nd.left:
                re += debug_node(nd.left)
            if nd.value: re.append(debug_info(nd))
            if nd.right:
                re += debug_node(nd.right)
            return re
        print("Debug - root =", self.root.value - 1, debug_node(self.root)[:50])

    def append(self, v):
        v += 1
        nd = self.root
        while True:
            if v == nd.value:

                return 0
            else:
                nd.cnt+=1
                nd.sum+=v-1
                mi, ma = min(v, nd.value), max(v, nd.value)
                if mi < nd.pivot:
                    nd.value = ma
                    if nd.left:
                        nd = nd.left
                        v = mi
                    else:
                        p = nd.pivot
                        nd.left = self.node(mi, p - (p&-p)//2)
                        break
                else:
                    nd.value = mi
                    if nd.right:
                        nd = nd.right
                        v = ma
                    else:
                        p = nd.pivot
                        nd.right = self.node(ma, p + (p&-p)//2)
                        break

    def kth(self,k):
        cnt=k
        nd=self.root
        while True:
            if nd.left:
                if nd.left.cnt<k:
                    k-=nd.left.cnt+1
                    if nd.right:
                        nd=nd.right
                    else:
                        raise IndexError("BalancingTree doesn't hold kth number")
                elif nd.left.cnt==k:
                    return nd.value-1
                else:
                    nd=nd.left
            else:
                if k==0:
                    return nd.value-1
                if nd.right:
                    k-=1
                    nd=nd.right
                else:
                    raise IndexError("BalancingTree doesn't hold kth number")

    def kth_sum(self,k):
        if k==-1:
            return 0
        cnt=k
        res_sum=0
        nd=self.root
        while True:
            if nd.left:
                if nd.left.cnt<k:
                    k-=nd.left.cnt+1
                    res_sum+=nd.left.sum+nd.value-1
                    if nd.right:
                        nd=nd.right
                    else:
                        raise IndexError("BalancingTree doesn't hold kth number")
                elif nd.left.cnt==k:
                    res_sum+=nd.left.sum+nd.value-1
                    return res_sum
                else:
                    nd=nd.left
            else:
                if k==0:
                    return res_sum+nd.value-1
                if nd.right:
                    k-=1
                    res_sum+=nd.value-1
                    nd=nd.right
                else:
                    print(cnt,self.size,nd.value-1,nd.right)
                    self.debug()
                    raise IndexError("BalancingTree doesn't hold kth number")

    def kth_sum_big(self,k):
        res_sum=self.sum
        if self.size>k:
            res_sum-=self.kth_sum(self.size-k-2)
            return res_sum
        else:
            raise IndexError("BalancingTree doesn't hold kth number")

    def leftmost(self, nd):
        if nd.left: return self.leftmost(nd.left)
        return nd

    def rightmost(self, nd):
        if nd.right: return self.rightmost(nd.right)
        return nd

    def find_l(self, v):
        v += 1
        nd = self.root
        prev = 0
        if nd.value < v: prev = nd.value
        while True:
            if v <= nd.value:
                if nd.left:
                    nd = nd.left
                else:
                    return prev - 1
            else:
                prev = nd.value
                if nd.right:
                    nd = nd.right
                else:
                    return prev - 1

    def find_r(self, v):
        v += 1
        nd = self.root
        prev = 0
        if nd.value > v: prev = nd.value
        while True:
            if v < nd.value:
                prev = nd.value
                if nd.left:
                    nd = nd.left
                else:
                    return prev - 1
            else:
                if nd.right:
                    nd = nd.right
                else:
                    return prev - 1

    @property
    def max(self):
        if self.size:
            return self.find_l((1<<self.N)-1)
        return 0

    @property
    def min(self):
        if self.size:
            return self.find_r(-1)
        return 0

    @property
    def sum(self):
        return self.root.sum-self.root.value+1

    @property
    def size(self):
        return self.root.cnt-1

    def delete(self, v, nd = None, prev = None):
        v += 1
        if not nd: nd = self.root
        if not prev: prev = nd
        while v != nd.value:
            prev = nd
            nd.cnt-=1
            nd.sum-=v-1
            if v <= nd.value:
                if nd.left:
                    nd = nd.left
                else:
                    return
            else:
                if nd.right:
                    nd = nd.right
                else:
                    return
        nd.cnt-=1
        nd.sum-=v-1
        if (not nd.left) and (not nd.right):
            if not prev.left:
                prev.right=None
            elif not prev.right:
                prev.left=None
            else:
                if nd.pivot==prev.left.pivot:
                    prev.left=None
                else:
                    prev.right=None
        elif nd.right:
            nd.value = self.leftmost(nd.right).value
            self.delete(nd.value - 1, nd.right, nd)
        else:
            nd.value = self.rightmost(nd.left).value
            self.delete(nd.value - 1, nd.left, nd)


    def __contains__(self, v: int) -> bool:
        return self.find_r(v - 1) == v

    def __len__(self):
        return self.size

    class node:
        def __init__(self, v, p):
            self.value = v
            self.pivot = p
            self.left = None
            self.right = None
            self.cnt=1
            self.sum=v-1

import sys

input=sys.stdin.readline

n=int(input())
xybst=BalancingTree(30)
S=0
split_bst=[BalancingTree(30),BalancingTree(30)]

for _ in range(n):
    t,d=map(int,input().split())
    if d<0:
        split_bst[t].delete(abs(d))
        xybst.delete(abs(d))
    else:
        split_bst[t].append(abs(d))
        xybst.append(abs(d))
    S+=d
    x,y=len(split_bst[0]),len(split_bst[1])
    tmp,tmpy=xybst.kth_sum_big(y-1),split_bst[1].kth_sum_big(y-1)
    if tmp==tmpy:
        print(S+tmp-split_bst[1].min+split_bst[0].max)
    else:
        print(S+tmp)