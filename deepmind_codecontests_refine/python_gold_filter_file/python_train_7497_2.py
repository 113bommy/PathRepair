class RSQ:
    def __init__(self, length, ini_num = float("inf")):
        self.length = 1
        self.ini_num = ini_num
        if length == 1:
            length = 2
        while self.length < length:
            self.length <<= 1
        self.segtree = [ini_num] * (2 * self.length - 1)

    def update(self, index, num):
        leaf_index = index + self.length - 1
        self.segtree[leaf_index] = num
        while leaf_index > 0:
            leaf_index = (leaf_index - 1) // 2
            self.segtree[leaf_index] = self.segtree[2 * leaf_index + 1] + self.segtree[2 * leaf_index + 2]

    def add(self, index, num):
        leaf_index = index + self.length - 1
        self.segtree[leaf_index] += num
        while leaf_index > 0:
            leaf_index = (leaf_index - 1) // 2
            self.segtree[leaf_index] = self.segtree[2 * leaf_index + 1] + self.segtree[2 * leaf_index + 2]

    def call_search(self, a, b):
        return self.search(a, b, index = 0, l = 0, r = self.length - 1)

    def search(self, a, b, index, l, r):
        if a <= l <= r <= b:
            return self.segtree[index]
        elif r < a or b < l:
            return self.ini_num
        else:
            return self.search(a, b, index * 2 + 1, l, (l + r) // 2) + self.search(a, b, index * 2 + 2, (l + r) // 2 + 1, r)

v_num, query = map(int, input().split(" "))
rsq = RSQ(v_num, 0)
for _ in range(query):
    comm, index, num = map(int, input().split(" "))
    if comm == 0:
        rsq.add(index - 1, num)
    else:
        print(rsq.call_search(index - 1, num - 1))