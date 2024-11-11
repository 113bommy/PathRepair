import sys
readline = sys.stdin.readline

class Node:
    def __init__(self, sigma, depth):
        self.end = False
        self.child = [None] * sigma
        self.depth = depth
    def __setitem__(self, i, x):
        self.child[i] = x
    def __getitem__(self, i):
        return self.child[i]

class Trie():
    def __init__(self, sigma):
        self.sigma = sigma
        self.root = Node(sigma, 0)
    
    def add(self, S):
        vn = self.root
        for cs in S:
            if vn[cs] is None:
                vn[cs] = Node(sigma, vn.depth + 1)
            vn = vn[cs]
        vn.end = True

ans = 0

N, L = map(int, readline().split())

Tr = Trie(2)

for _ in range(N):
    S = list(map(int, readline().strip()))
    Tr.add(S)

cnt = 0
stack = [Tr.root]
while stack:
    vn = stack.pop()
    for i in range(2):
        if vn[i] is None:
            r = L - vn.depth
            cnt ^= -r&r
        else:
            stack.append(vn[i])

print('Alice' if cnt else 'Bob')