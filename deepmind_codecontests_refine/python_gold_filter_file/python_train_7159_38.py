from sys import stdin
input = stdin.readline


class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s

    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i


N, Q = map(int, input().split())
c = list(map(int, input().split()))

lr = []
for i in range(Q):
    l, r = map(int, input().split())
    lr.append([l, r, i])

lr.sort(key=lambda x: x[1])
# print("lr", lr)
rightest = [-1] * (N + 1)
current_q = 0
bit = Bit(N)
ans = [0] * Q

for i in range(N):
    if rightest[c[i]] != -1:
        bit.add(rightest[c[i]] + 1, -1)
    rightest[c[i]] = i
    bit.add(i + 1, 1)
    # print(bit.tree)

    while current_q < Q and lr[current_q][1] == i + 1:
        ans[lr[current_q][2]] = bit.sum(lr[current_q][1]) - bit.sum(lr[current_q][0] - 1)
        current_q += 1

for i in range(Q):
    print(ans[i])
