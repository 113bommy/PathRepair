class FenwickTree:
    def __init__(self, size):
        self.size = size
        self.array = [0]*size
 
    def add(self, index, value):
        while index < self.size:
            self.array[index] += value
            index += index&(-index)
 
    def sum(self, index):
        answer = 0
        while index > 0:
            answer += self.array[index]
            index -= index&(-index)
        return answer
 
    def rangesum(self, start, end):
        return self.sum(end)-self.sum(start-1)


def solve():
    N, Q = map(int, input().split())
    *c, = map(int, input().split())
    tree2 = FenwickTree(N+1)
    m = [list(map(int, input().split())) for _ in range(Q)]
    idxs = sorted(list(range(Q)), key=lambda i: m[i][1])

    right = 0
    pos = [-1] * (N+1)
    ans = [-1] * (Q)

    for idx in idxs:
        l, r = m[idx]
        for i in range(right, r):
            x = pos[c[i]]
            if x != -1:
                tree2.add(x, -1)
            pos[c[i]] = i+1
            tree2.add(i+1, 1)
        ans[idx] = tree2.rangesum(l, r)
        right = r
    print(*ans, sep="\n")


if __name__ == '__main__':
    solve()
