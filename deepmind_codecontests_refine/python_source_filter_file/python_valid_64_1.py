import sys
input = sys.stdin.readline


class Node:
    def __init__(self, index, p=None, rank=None):
        self.index = index
        self.p = p
        self.rank = rank

    def make_set(self):
        self.p = self
        self.rank = 0

    def find_set(self):
        if self != self.p:
            self.p = self.p.find_set()
        return self.p

    def link(self, x):
        if self.rank > x.rank:
            x.p = self
        else:
            self.p = x
            if self.rank == x.rank:
                x.rank += 1

    def union(self, x):
        return (self.find_set()).link(x.find_set())


n, m1, m2 = list(map(int, input().split()))
inp1 = [list(map(int, input().split())) for _ in range(m1)]
inp2 = [list(map(int, input().split())) for _ in range(m2)]
arr1 = [Node(i) for i in range(n)]
for i in arr1:
    i.make_set()
arr2 = [Node(i) for i in range(n)]
queue1 = list(range(n-1, -1, -1))
queue2 = list(range(n-1, -1, -1))
for i in arr2:
    i.make_set()
for (i, j) in inp1:
    arr1[i-1].union(arr1[j-1])
for (i, j) in inp2:
    arr2[i-1].union(arr2[j-1])
ans1 = 0
ans2 = []
end = 0
while len(queue1) >= 2 and len(queue2) >= 2:
    end = 0
    while True:
        if len(queue1) >= 2:
            i1, i2 = queue1[-1], queue2[-2]
            x1, x2 = arr1[i1].find_set(), arr1[i2].find_set()
            if x1 is x2:
                queue1.pop(-1)
                continue
            else:
                i1, i2 = x1.index, x2.index
                break
        else:
            end = 1
            break
    while True:
        if len(queue2) >= 2:
            i3, i4 = queue2[-1], queue2[-2]
            x3, x4 = arr2[i3].find_set(), arr2[i4].find_set()
            if x3 is x4:
                queue2.pop(-1)
                continue
            else:
                i3, i4 = x3.index, x4.index
                break
        else:
            end = 1
            break
    if end:
        break
    for x in (i1, i2, i3, i4):
        for y in (i1, i2, i3, i4):
            if x!=y:
                if arr1[x].find_set() is arr1[y].find_set():
                    continue
                if arr2[x].find_set() is arr2[y].find_set():
                    continue
                end = 1
                break
        if end:
            break
    arr1[x].union(arr1[y])
    arr2[x].union(arr2[y])
    ans1 += 1
    ans2.append((x+1, y+1))
print(ans1)
for (i, j) in ans2:
    print(str(i) + ' ' + str(j))




