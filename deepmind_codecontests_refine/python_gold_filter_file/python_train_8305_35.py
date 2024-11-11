import time
import random


class TreapNode:
    def __init__(self, key, pri):
        self.left = None
        self.right = None
        self.key = key
        self.pri = pri


class Treap:
    def __init__(self):
        self.nil = TreapNode(None, 0)
        self.root = self.nil

    def search_lower(self, key):
        if key == None:
            return None
        ptr = self.root
        ret = None
        nil = self.nil
        while ptr is not nil:
            pk = ptr.key
            if pk < key:
                ret = pk
                ptr = ptr.right
            else:
                ptr = ptr.left
        return ret

    def search_higher(self, key):
        if key == None:
            return None
        ptr = self.root
        ret = None
        nil = self.nil
        while ptr is not nil:
            pk = ptr.key
            if pk > key:
                ret = pk
                ptr = ptr.left
            else:
                ptr = ptr.right
        return ret

    def insert(self, key):
        pri = random.randrange(1, 2**32)
        ptr = self.root
        elem = TreapNode(key, pri)
        if ptr.pri < pri:
            self.root = elem
        else:
            while True:
                if key < ptr.key:
                    left = ptr.left
                    if left.pri < pri:
                        ptr.left = elem
                        ptr = left
                        break
                    ptr = left
                else:
                    right = ptr.right
                    if right.pri < pri:
                        ptr.right = elem
                        ptr = right
                        break
                    ptr = right
        left = elem
        right = elem
        nil = self.nil
        while ptr is not nil:
            if key < ptr.key:
                right.left = ptr
                right = ptr
                ptr = ptr.left
            else:
                left.right = ptr
                left = ptr
                ptr = ptr.right
        left.right = nil
        right.left = nil
        elem.left, elem.right = elem.right, elem.left

# デバッグ用
    def dump(self):
        self.__dump(self.root, 0)

    def __dump(self, idx, dep):
        if idx is not self.nil:
            self.__dump(idx.right, dep + 1)
            for _ in range(0, dep):
                print("   ", end="")
            print([idx.key, idx.pri])
            self.__dump(idx.left, dep + 1)

def main():
    n = int(input())
    p = list(map(int, input().split()))
    idx = [0] * n
    for i in range(0, n):
        idx[i] = i
    idx.sort(key=lambda i: - p[i])
    t = Treap()
    t.insert(-1)
    t.insert(n)
    ans = 0
    for i in idx:
        nex = t.search_higher(i)
        nexnex = t.search_higher(nex)
        pre = t.search_lower(i)
        prepre = t.search_lower(pre)
        if prepre != None:
            ans += p[i] * (pre - prepre) * (nex - i)
        if nexnex != None:
            ans += p[i] * (i - pre) * (nexnex - nex)
        t.insert(i)
    print(ans)


main()
