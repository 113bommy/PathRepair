import sys
readline = sys.stdin.readline
from operator import itemgetter

class UF():
    def __init__(self, num):
        self.par = [-1]*num
    def find(self, x):
        if self.par[x] < 0:
            return x
        else:
            stack = []
            while self.par[x] >= 0:
                stack.append(x)
                x = self.par[x]
            for xi in stack:
                self.par[xi] = x
            return x
    
    def union(self, x, y):
        rx = self.find(x)
        ry = self.find(y)
        if rx != ry:
            if self.par[rx] > self.par[ry]:
                rx, ry = ry, rx
            self.par[rx] += self.par[ry]
            self.par[ry] = rx
        return rx

N = int(readline())
XY = []
for i in range(N):
    x, y = map(int, readline().split())
    XY.append((i, x, y))

_, _, Y = map(list, zip(*XY))

XY.sort(key = itemgetter(1))

T = UF(N)

stack = []
for i, _, y in XY:
    my = i
    while stack and Y[stack[-1]] < y:
        if stack[-1] < y:
            my = stack[-1]
        T.union(stack.pop(), i)
    stack.append(my)
ans = [-T.par[T.find(i)] for i in range(N)]
    
print('\n'.join(map(str, ans)))